#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

// ------------------ DSU with rollback ------------------
struct DSU {
    vector<int> parent, size;
    stack<tuple<int, int, int>> history;  // {y, old_parent_y, size_parent_x}

    DSU(int n) {
        parent.resize(n+1);
        size.assign(n+1, 1);
        for (int i = 1; i <= n; ++i)
            parent[i] = i;
    }

    int find(int u) {
        while (u != parent[u]) u = parent[u];
        return u;
    }

    void unite(int he, int v) {
        he = find(he); v = find(v);
        if (he == v) return;
        if (size[he] < size[v]) swap(he, v);
        history.push({v, parent[v], size[he]});
        parent[v] = he;
        size[he] += size[v];
    }

    void rollback(int checkpoint_size) {
        while ((int)history.size() > checkpoint_size) {
            auto [v, old_parent, old_size] = history.top(); history.pop();
            parent[v] = old_parent;
            size[parent[v]] = old_size;
        }
    }
};

// ------------------ Segment Tree (trên thời gian) ------------------
vector<pair<int, int>> segTree[4 * MAXN];  // mỗi node lưu các cạnh (he, v)

// gắn cạnh (he,v) vào đoạn [l, r)
void add_edge(int id, int l, int r, int he, int v, int ql, int qr) {
    if (qr <= l || r <= ql) return;  // không giao nhau
    if (ql <= l && r <= qr) {
        segTree[id].emplace_back(he, v);
        return;
    }
    int mid = (l + r) / 2;
    add_edge(id*2, l, mid, he, v, ql, qr);
    add_edge(id*2+1, mid, r, he, v, ql, qr);
}

// ------------------ Xử lý truy vấn ------------------

struct Query {
    int type, x, y;
};
vector<Query> queries;
map<pair<int, int>, vector<int>> edge_time;  // lưu lại thời điểm xuất hiện của cạnh

vector<int> ans;  // kết quả các truy vấn loại 3

void dfs(int id, int l, int r, DSU &dsu) {
    int checkpoint = dsu.history.size();  // lưu lại trạng thái DSU trước khi thêm cạnh

    // Thêm các cạnh vào DSU
    for (auto [he, v] : segTree[id])
        dsu.unite(he, v);

    if (l + 1 == r) {
        // Đây là một truy vấn
        auto [t, x, y] = queries[l];
        if (t == 3) {
            ans.push_back(dsu.find(x) == dsu.find(y));
        }
    } else {
        int mid = (l + r) / 2;
        dfs(id*2, l, mid, dsu);
        dfs(id*2+1, mid, r, dsu);
    }

    dsu.rollback(checkpoint);  // hoàn tác DSU
}

// ------------------ Main ------------------

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    queries.resize(Q);
    for (int i = 0; i < Q; ++i) {
        int t, x, y;
        cin >> t >> x >> y;
        if (x > y) swap(x, y);  // để đồng nhất thứ tự
        queries[i] = {t, x, y};

        if (t == 1) {
            edge_time[{x, y}].push_back(i);  // bắt đầu tồn tại tại i
        }
        else if (t == 2) {
            auto &v = edge_time[{x, y}];
            if (!v.empty()) {
                int start = v.back(); v.pop_back();
                add_edge(1, 0, Q, x, y, start, i);
            }
        }
    }

    // Sau cùng: những cạnh chưa bị xóa thì tồn tại tới hết
    for (auto &[edge, times] : edge_time) {
        for (int start : times) {
            add_edge(1, 0, Q, edge.first, edge.second, start, Q);
        }
    }

    DSU dsu(N);
    dfs(1, 0, Q, dsu);

    for (int v : ans) cout << v << '\n';

    return 0;
}
