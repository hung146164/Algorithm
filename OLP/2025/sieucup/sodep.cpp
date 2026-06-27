#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// Tối ưu I/O
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int MAXN = 200005;
const long long INF = 1e18;

struct Edge {
    int to;
    long long weight;
};

vector<Edge> adj[MAXN];
int N, Q;

// Thông tin lưu trữ cho mỗi đỉnh sau khi Rerooting DP
// Top 3 độ sâu lớn nhất (kèm ID hàng xóm để loại trừ)
// Top 2 đường kính lớn nhất (kèm ID hàng xóm)
struct NodeData {
    vector<pair<long long, int>> depths; // {length, neighbor_id}
    vector<pair<long long, int>> diams;  // {diameter, neighbor_id}
} node_data[MAXN];

// HLD & Tree variables
int parent[MAXN];
int heavy[MAXN];
int head[MAXN];
int pos[MAXN];
int depth_idx[MAXN];
long long dist_root[MAXN]; // Khoảng cách từ root (để tính khoảng cách nhanh)
int cur_pos;

// DP mảng tạm
long long dp_down_depth[MAXN];
long long dp_down_diam[MAXN];

// Segment Tree Node
struct NodeST {
    long long max_diam;
    long long max_d1;
    long long max_d2;

    NodeST() : max_diam(0), max_d1(-INF), max_d2(-INF) {}

    static NodeST merge(const NodeST& l, const NodeST& r) {
        NodeST res;
        res.max_diam = max(l.max_diam, r.max_diam);

        // Lấy top 2 depth từ cả 2 phía
        long long d[4] = {l.max_d1, l.max_d2, r.max_d1, r.max_d2};
        // Sort thủ công 4 phần tử để lấy top 2
        for(int i=0; i<3; ++i)
            for(int j=i+1; j<4; ++j)
                if(d[j] > d[i]) swap(d[i], d[j]);

        res.max_d1 = d[0];
        res.max_d2 = d[1];
        return res;
    }

    // Hàm tạo node từ thông tin đỉnh u, loại trừ p và heavy_child
    static NodeST from_node(int u, int forbid1, int forbid2) {
        NodeST res;

        // Lấy max diam
        for (auto& p : node_data[u].diams) {
            if (p.second != forbid1 && p.second != forbid2) {
                res.max_diam = p.first;
                break;
            }
        }

        // Lấy top 2 depths
        int count = 0;
        for (auto& p : node_data[u].depths) {
            if (p.second != forbid1 && p.second != forbid2) {
                if (count == 0) res.max_d1 = p.first;
                else if (count == 1) res.max_d2 = p.first;
                count++;
                if (count >= 2) break;
            }
        }
        if (count < 1) res.max_d1 = 0;
        if (count < 2) res.max_d2 = 0; // Thực tế độ sâu luôn >= 0

        return res;
    }
};

NodeST tree[4 * MAXN];

// --- Giai đoạn 1: Tree DP & HLD Prep ---

int dfs_sz(int u, int p, long long d) {
    parent[u] = p;
    dist_root[u] = d;
    depth_idx[u] = (p == -1 ? 0 : depth_idx[p] + 1);
    int size = 1;
    int max_sz = 0;
    heavy[u] = -1;

    dp_down_depth[u] = 0;
    dp_down_diam[u] = 0;

    // Tạm thời lưu top depths/diams từ con để dùng cho rerooting sau
    // Nhưng để tiết kiệm, ta làm 2 DFS riêng biệt hoặc kết hợp khéo léo.
    // Ở đây dùng cách chuẩn: DFS 1 tính down, DFS 2 tính up.

    for (auto& e : adj[u]) {
        if (e.to != p) {
            int c_sz = dfs_sz(e.to, u, d + e.weight);
            size += c_sz;
            if (c_sz > max_sz) {
                max_sz = c_sz;
                heavy[u] = e.to;
            }

            dp_down_depth[u] = max(dp_down_depth[u], dp_down_depth[e.to] + e.weight);
            dp_down_diam[u] = max(dp_down_diam[u], dp_down_diam[e.to]);
        }
    }

    // Cập nhật diam nội tại đi qua u từ 2 con lớn nhất
    long long max1 = 0, max2 = 0;
    for (auto& e : adj[u]) {
        if (e.to != p) {
            long long val = dp_down_depth[e.to] + e.weight;
            if (val > max1) {
                max2 = max1;
                max1 = val;
            } else if (val > max2) {
                max2 = val;
            }
        }
    }
    dp_down_diam[u] = max(dp_down_diam[u], max1 + max2);

    return size;
}

void dfs_reroot(int u, int p, long long up_len, long long up_diam_val) {
    // Thu thập tất cả các nhánh (con + cha)
    struct Branch {
        long long len; // Length đi ra từ u
        long long diam; // Diam của thành phần đó
        int id;
    };
    vector<Branch> branches;

    if (p != -1) {
        branches.push_back({up_len, up_diam_val, p});
    }

    for (auto& e : adj[u]) {
        if (e.to != p) {
            branches.push_back({dp_down_depth[e.to] + e.weight, dp_down_diam[e.to], e.to});
        }
    }

    // Lưu vào node_data (Sắp xếp để query nhanh)
    // 1. Depths
    sort(branches.begin(), branches.end(), [](const Branch& a, const Branch& b){
        return a.len > b.len;
    });
    for(int i=0; i < min((int)branches.size(), 3); ++i) {
        node_data[u].depths.push_back({branches[i].len, branches[i].id});
    }

    // 2. Diams
    sort(branches.begin(), branches.end(), [](const Branch& a, const Branch& b){
        return a.diam > b.diam;
    });
    for(int i=0; i < min((int)branches.size(), 2); ++i) {
        node_data[u].diams.push_back({branches[i].diam, branches[i].id});
    }

    // Chuẩn bị dữ liệu đẩy xuống con (Prefix/Suffix max trick)
    int k = adj[u].size(); // bao gồm cả cha nếu có trong adj, nhưng ta chỉ iter con
    // Để tối ưu O(N), ta cần prefix suffix max cho children.
    // Lọc ra danh sách children
    vector<pair<int, long long>> children; // id, weight
    for(auto& e : adj[u]) if(e.to != p) children.push_back({e.to, e.weight});

    if (children.empty()) return;

    int sz = children.size();
    vector<long long> pref_len(sz, -INF), suff_len(sz, -INF);
    vector<long long> pref_diam(sz, -INF), suff_diam(sz, -INF);

    // Fill arrays from children info
    for(int i=0; i<sz; ++i) {
        int v = children[i].first;
        long long w = children[i].second;
        pref_len[i] = dp_down_depth[v] + w;
        pref_diam[i] = dp_down_diam[v];
    }

    // Xây dựng Prefix
    for(int i=1; i<sz; ++i) {
        pref_diam[i] = max(pref_diam[i], pref_diam[i-1]); // Max diam con
        // Diam tạo bởi 2 nhánh trong prefix? Khó.
        // Cách đơn giản hơn: Chỉ cần max len và max diam của từng thành phần.
        // Diam mới khi cắt nhánh con i đi là:
        // Max(up_diam, max(diam các anh em khác), top 1 len anh em + top 2 len anh em, top 1 len anh em + up_len)
        // Phần này hơi phức tạp để code "trâu", nhưng với N=2e5 cần O(N).
    }
    // Suffix
    suff_len = pref_len; suff_diam = pref_diam; // Init copy base values
    for(int i=sz-2; i>=0; --i) {
        suff_len[i] = max(suff_len[i], suff_len[i+1]);
        suff_diam[i] = max(suff_diam[i], suff_diam[i+1]);
    }
    for(int i=1; i<sz; ++i) {
        pref_len[i] = max(pref_len[i], pref_len[i-1]);
        pref_diam[i] = max(pref_diam[i], pref_diam[i-1]);
    }

    // Để tính chính xác "Diam phần còn lại" cho con i:
    // Cần lấy Top 2 length từ tập {up_len, các anh em khác} + Max diam từ tập {up_diam, các anh em khác}.
    // Ta dùng lại logic sort branches lúc nãy nhưng loại bỏ con i.
    // Vì số lượng branches nhỏ (degree), nhưng tổng degree = 2N, nên sort lại mỗi lần cũng được?
    // Không, nếu 1 đỉnh nối 10^5 đỉnh thì TLE.
    // Dùng Top 3 đã lưu trong node_data[u].

    for (auto& child_pair : children) {
        int v = child_pair.first;
        long long w = child_pair.second;

        // Tính new_up_len cho v
        // Lấy max length từ node_data[u].depths mà id != v
        long long best_len = 0;
        for(auto& p : node_data[u].depths) {
            if(p.second != v) {
                best_len = p.first;
                break;
            }
        }
        long long next_up_len = best_len + w;

        // Tính new_up_diam cho v
        // 1. Max diam từ các thành phần khác (bao gồm up_diam cũ và các anh em)
        long long best_diam_comp = 0;
        for(auto& p : node_data[u].diams) {
            if(p.second != v) {
                best_diam_comp = p.first;
                break;
            }
        }

        // 2. Đường kính đi qua u (kết hợp 2 nhánh dài nhất không phải v)
        long long max_path_thru_u = 0;
        long long l1 = 0, l2 = 0;
        int c = 0;
        for(auto& p : node_data[u].depths) {
            if(p.second != v) {
                if(c==0) l1 = p.first;
                else if(c==1) l2 = p.first;
                c++;
                if(c>=2) break;
            }
        }
        max_path_thru_u = l1 + l2;

        long long next_up_diam = max(best_diam_comp, max_path_thru_u);

        dfs_reroot(v, u, next_up_len, next_up_diam);
    }
}

// HLD Decomposition
void dfs_hld(int u, int h) {
    head[u] = h;
    pos[u] = ++cur_pos;
    if (heavy[u] != -1) dfs_hld(heavy[u], h);
    for (auto& e : adj[u]) {
        if (e.to != parent[u] && e.to != heavy[u]) {
            dfs_hld(e.to, e.to);
        }
    }
}

// --- Segment Tree Operations ---
void build_st(int node, int start, int end) {
    if (start == end) {
        // Map ngược pos -> u để lấy dữ liệu
        // Nhưng ta không cần map ngược, ta có thể fill lúc dfs hoặc loop qua các node.
        // Ta cần biết node nào có pos = start.
        return;
    }
    int mid = (start + end) / 2;
    build_st(2 * node, start, mid);
    build_st(2 * node + 1, mid + 1, end);
    // Merge ko làm gì vì chưa có data
}

void update_st(int node, int start, int end, int idx, const NodeST& val) {
    if (start == end) {
        tree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid) update_st(2 * node, start, mid, idx, val);
    else update_st(2 * node + 1, mid + 1, end, idx, val);
    tree[node] = NodeST::merge(tree[2 * node], tree[2 * node + 1]);
}

NodeST query_st(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return NodeST();
    if (l <= start && end <= r) return tree[node];
    int mid = (start + end) / 2;
    return NodeST::merge(query_st(2 * node, start, mid, l, r),
                         query_st(2 * node + 1, mid + 1, end, l, r));
}

// --- Main Solver ---

void solve() {
    if (!(cin >> N)) return;

    // Reset global data
    for(int i=0; i<=N; ++i) {
        adj[i].clear();
        node_data[i].depths.clear();
        node_data[i].diams.clear();
    }
    cur_pos = 0;

    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // 1. Build Tree & Down DP
    dfs_sz(1, -1, 0);

    // 2. Rerooting DP
    dfs_reroot(1, -1, 0, 0);

    // 3. HLD
    dfs_hld(1, 1);

    // 4. Build SegTree Data
    // Với mỗi node u, tính giá trị "Static" giả định nó nằm giữa heavy chain
    // Tức là loại bỏ parent[u] và heavy[u].
    for(int i=1; i<=N; ++i) {
        NodeST val = NodeST::from_node(i, parent[i], heavy[i]);
        update_st(1, 1, N, pos[i], val);
    }

    cin >> Q;
    while(Q--) {
        int A, B;
        cin >> A >> B;

        int u = A, v = B;
        NodeST res; // Neutral element

        int last_u = -1; // Đỉnh con trên đường đi về phía A
        int last_v = -1; // Đỉnh con trên đường đi về phía B

        // HLD LCA Process
        while (head[u] != head[v]) {
            if (depth_idx[head[u]] > depth_idx[head[v]]) {
                // Nhảy u lên
                // Đoạn heavy path: từ u lên đến head[u] (hoặc đoạn con của nó)
                // Các đỉnh từ parent[u] đến head[u] (inclusive) dùng heavy edges.
                // u xử lý riêng vì bị chặn bởi last_u.

                // 1. Xử lý u: cấm last_u và parent[u]
                res = NodeST::merge(res, NodeST::from_node(u, last_u, parent[u]));

                // 2. Xử lý đoạn giữa (nếu có): pos[head[u]] đến pos[parent[u]]
                // Trong đoạn này, mọi đỉnh đều dùng Heavy Child và Parent làm đường đi.
                // Trùng khớp với StaticVal trong SegTree.
                if (parent[u] != -1 && pos[head[u]] <= pos[parent[u]]) {
                    res = NodeST::merge(res, query_st(1, 1, N, pos[head[u]], pos[parent[u]]));
                }

                last_u = head[u]; // head[u] là con của parent[head[u]]
                u = parent[head[u]];
            } else {
                // Nhảy v lên (tương tự u)
                res = NodeST::merge(res, NodeST::from_node(v, last_v, parent[v]));

                if (parent[v] != -1 && pos[head[v]] <= pos[parent[v]]) {
                    res = NodeST::merge(res, query_st(1, 1, N, pos[head[v]], pos[parent[v]]));
                }

                last_v = head[v];
                v = parent[head[v]];
            }
        }

        // Giờ u và v cùng chain. Giả sử depth[u] < depth[v] thì swap để xử lý
        // Nhưng cần giữ last_u, last_v đúng tương ứng.
        if (depth_idx[u] > depth_idx[v]) {
            swap(u, v);
            swap(last_u, last_v);
        }
        // Giờ u là LCA hoặc nằm trên u..v, u ở trên, v ở dưới.
        // Đường đi là v đi lên tới u.
        // Đoạn từ v lên con của u.
        // last_v là đỉnh con (vừa xử lý) đi vào v.
        // u là đỉnh cao nhất (LCA).

        // Xử lý v lên tới con của u.
        // Lưu ý: nếu u == v (ban đầu), thì đây chính là LCA.

        if (u != v) {
            // Xử lý nhánh v (đi lên)
            // 1. Tại v (đáy hiện tại của chain): cấm last_v và parent[v]
            res = NodeST::merge(res, NodeST::from_node(v, last_v, parent[v]));

            // 2. Đoạn giữa: từ heavy_child[u] xuống parent[v]
            // Con trực tiếp của u trên chain này là heavy[u] (vì cùng chain)
            int son_of_u = heavy[u];
            if (pos[son_of_u] <= pos[parent[v]]) {
                res = NodeST::merge(res, query_st(1, 1, N, pos[son_of_u], pos[parent[v]]));
            }

            // Cập nhật last_v thành son_of_u để dùng cho việc cấm tại u
            last_v = son_of_u;
        }

        // Cuối cùng xử lý LCA (là u)
        // Cấm last_u (hướng A) và last_v (hướng B)
        res = NodeST::merge(res, NodeST::from_node(u, last_u, last_v));

        // Kết quả: max(max_diam nội bộ các thành phần, tổng 2 nhánh dài nhất treo vào)
        long long ans = max(res.max_diam, res.max_d1 + res.max_d2);
        cout << ans << "\n";
    }
}

int main() {
    fast_io();
    int T;
    if (cin >> T) {
        while(T--) {
            solve();
        }
    }
    return 0;
}
