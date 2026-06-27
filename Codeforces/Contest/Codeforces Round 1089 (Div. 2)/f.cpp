#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;
const long long INF = 2e18;

int p[MAXN];
int nle[MAXN];
int path_arr[MAXN];

// Đồ thị biểu diễn NLE Tree
int head_edge[MAXN], to_edge[MAXN], nxt_edge[MAXN], edge_cnt;
void add_edge(int u, int v) {
    to_edge[++edge_cnt] = v;
    nxt_edge[edge_cnt] = head_edge[u];
    head_edge[u] = edge_cnt;
}

// Danh sách các truy vấn
int q_head[MAXN], q_to[MAXN], q_nxt[MAXN], q_idx[MAXN], q_cnt;
void add_query(int u, int r, int idx) {
    q_to[++q_cnt] = r;
    q_idx[q_cnt] = idx;
    q_nxt[q_cnt] = q_head[u];
    q_head[u] = q_cnt;
}

long long ans_arr[MAXN];

struct Node {
    long long MaxD;
    long long SumB;
    long long SumBv;
} tree[4 * MAXN];

void build(int node, int L, int R) {
    tree[node].MaxD = -INF;
    tree[node].SumB = 0;
    tree[node].SumBv = 0;
    if (L == R) return;
    int mid = L + (R - L) / 2;
    build(2 * node, L, mid);
    build(2 * node + 1, mid + 1, R);
}

void update(int node, int L, int R, int pos, long long B, long long u) {
    if (L == R) {
        tree[node].MaxD = B - u;
        tree[node].SumB = B;
        tree[node].SumBv = B * u;
        return;
    }
    int mid = L + (R - L) / 2;
    if (pos <= mid) update(2 * node, L, mid, pos, B, u);
    else update(2 * node + 1, mid + 1, R, pos, B, u);

    tree[node].MaxD = max(tree[2 * node].MaxD, tree[2 * node + 1].MaxD);
    tree[node].SumB = tree[2 * node].SumB + tree[2 * node + 1].SumB;
    tree[node].SumBv = tree[2 * node].SumBv + tree[2 * node + 1].SumBv;
}

long long best_c(long long B, long long diff) {
    long long c1 = min(B, max(0LL, diff / 2));
    long long c2 = min(B, max(0LL, (diff + 1) / 2));
    return max(c1 * (diff - c1), c2 * (diff - c2));
}

long long f_1(long long B) {
    long long x = (B - 1) / 2;
    long long y = B - 1 - x;
    return x * y;
}

void query_seg(int node, int L, int R, int qL, int qR, long long l, long long &ans) {
    if (L > qR || R < qL) return;
    if (qL <= L && R <= qR) {
        // Tối ưu quan trọng: Nếu tất cả đều tuyến tính, tính tổng O(1)
        if (tree[node].MaxD <= -l) {
            ans += tree[node].SumBv - tree[node].SumB * l;
            return;
        }
        if (L == R) {
            int u = path_arr[L];
            long long B = nle[u] - u;
            ans += best_c(B, nle[u] - l);
            return;
        }
    }
    int mid = L + (R - L) / 2;
    query_seg(2 * node, L, mid, qL, qR, l, ans);
    query_seg(2 * node + 1, mid + 1, R, qL, qR, l, ans);
}

void dfs(int u, int lvl, int n) {
    path_arr[lvl] = u;
    if (u <= n) {
        long long B = nle[u] - u;
        update(1, 1, n, lvl, B, u);
    }

    for (int i = q_head[u]; i; i = q_nxt[i]) {
        int r = q_to[i];
        int idx = q_idx[i];

        int low = 0, high = lvl, vk_lvl = lvl;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (path_arr[mid] > r) {
                low = mid + 1;
            } else {
                vk_lvl = mid;
                high = mid - 1;
            }
        }

        int vk = path_arr[vk_lvl];

        if (vk == u) {
            long long B1 = r + 1 - u;
            ans_arr[idx] = f_1(B1);
        } else {
            long long B1 = nle[u] - u;
            long long cur_ans = f_1(B1);

            long long Bk = r + 1 - vk;
            cur_ans += best_c(Bk, r + 1 - u);

            if (vk_lvl + 1 <= lvl - 1) {
                query_seg(1, 1, n, vk_lvl + 1, lvl - 1, u, cur_ans);
            }
            ans_arr[idx] = cur_ans;
        }
    }

    for (int i = head_edge[u]; i; i = nxt_edge[i]) {
        dfs(to_edge[i], lvl + 1, n);
    }
}

void solve() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n + 1; i++) {
        head_edge[i] = 0;
        q_head[i] = 0;
    }
    edge_cnt = 0;
    q_cnt = 0;

    for (int i = 1; i <= n; i++) cin >> p[i];

    vector<int> st;
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && p[st.back()] > p[i]) {
            nle[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    while (!st.empty()) {
        nle[st.back()] = n + 1;
        st.pop_back();
    }

    for (int i = 1; i <= n; i++) add_edge(nle[i], i);
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        add_query(l, r, i);
    }

    build(1, 1, n);
    dfs(n + 1, 0, n);

    for (int i = 1; i <= q; i++) {
        cout << ans_arr[i] << (i == q ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
