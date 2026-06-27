#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct EdgeInfo {
    int to;
    int v;   // current speed
    int c;   // cost to upgrade
    int s;   // speed after upgrade
};

int n;

bool canAchieveWithEdgesRange(const vector<int>& vs, const vector<int>& cs, const vector<int>& ss, int L, int R, ll money, int T) {
    // check edges indexed L..R inclusive
    ll cost = 0;
    for (int i = L; i <= R; ++i) {
        if (vs[i] >= T) continue;
        if (ss[i] < T) return false;
        cost += cs[i];
        if (cost > money) return false;
    }
    return cost <= money;
}

bool canAchieveWithVec(const vector<array<int,3>>& edges, ll money, int T) {
    ll cost = 0;
    for (auto &e : edges) {
        int v = e[0], c = e[1], s = e[2];
        if (v >= T) continue;
        if (s < T) return false;
        cost += c;
        if (cost > money) return false;
    }
    return cost <= money;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<vector<EdgeInfo>> adj(n+1);
    vector<tuple<int,int,int,int,int>> edgeList;
    for (int i = 0; i < n-1; ++i) {
        int x,y,v,c,s;
        cin >> x >> y >> v >> c >> s;
        adj[x].push_back({y,v,c,s});
        adj[y].push_back({x,v,c,s});
        edgeList.emplace_back(x,y,v,c,s);
    }

    // detect if path-like (degree <= 2 for all nodes)
    bool isPath = true;
    for (int i = 1; i <= n; ++i) {
        if ((int)adj[i].size() > 2) { isPath = false; break; }
    }

    // If path-like, build linear arrays of edges in order
    vector<int> pos(n+1, -1);
    vector<int> order; // node order along path
    vector<int> vs, cs, ss; // edges values along path between order[i] and order[i+1], indexed 0..(n-2)
    if (isPath) {
        // find endpoint (degree 1)
        int start = 1;
        for (int i = 1; i <= n; ++i) if (adj[i].size() == 1) { start = i; break; }
        order.reserve(n);
        vector<int> visited(n+1,0);
        int cur = start, prev = -1;
        while (true) {
            order.push_back(cur);
            visited[cur]=1;
            int nxt = -1;
            for (auto &e : adj[cur]) {
                if (e.to == prev) continue;
                nxt = e.to;
                // record edge info between cur and nxt
                vs.push_back(e.v);
                cs.push_back(e.c);
                ss.push_back(e.s);
                break;
            }
            if (nxt == -1) break;
            prev = cur;
            cur = nxt;
        }
        // note: vs/.. length == order.size()-1
        for (int i = 0; i < (int)order.size(); ++i) pos[order[i]] = i;
    }

    int Q; cin >> Q;
    while (Q--) {
        int a,b; long long money;
        cin >> a >> b >> money;

        // get edges along path
        if (isPath) {
            int pa = pos[a], pb = pos[b];
            if (pa == -1 || pb == -1) {
                cout << 0 << '\n'; // shouldn't happen
                continue;
            }
            int L = min(pa,pb);
            int R = max(pa,pb) - 1; // edges indices between nodes L..R inclusive in vs
            if (L > R) {
                // same node, min speed infinite? but by statement speed defined on edges -> if no edge, maybe output large?
                cout << 0 << '\n';
                continue;
            }
            // binary search max T
            int lo = 0, hi = 1000000000, ans = 0;
            while (lo <= hi) {
                int mid = lo + ((hi - lo) >> 1);
                if (canAchieveWithEdgesRange(vs, cs, ss, L, R, money, mid)) {
                    ans = mid;
                    lo = mid + 1;
                } else hi = mid - 1;
            }
            cout << ans << '\n';
        } else {
            // general small n case: find path by DFS (works for subtask1 where n,q <= 1000)
            // run DFS to get edges on path a->b
            vector<int> parent(n+1, -1);
            vector<array<int,3>> parentEdge(n+1); // v,c,s of edge from parent -> node
            stack<int> st;
            st.push(a);
            parent[a] = 0;
            bool found = false;
            while (!st.empty() && !found) {
                int u = st.top(); st.pop();
                if (u == b) { found = true; break; }
                for (auto &e : adj[u]) {
                    if (parent[e.to] == -1) {
                        parent[e.to] = u;
                        parentEdge[e.to] = {e.v, e.c, e.s};
                        st.push(e.to);
                    }
                }
            }
            vector<array<int,3>> pathEdges;
            if (!found) {
                cout << 0 << '\n';
                continue;
            }
            int cur = b;
            while (cur != a) {
                pathEdges.push_back(parentEdge[cur]); // edge (parent[cur] -> cur)
                cur = parent[cur];
            }
            // pathEdges currently from b->a, order doesn't matter for min-edge problem
            // binary search max T
            int lo = 0, hi = 1000000000, ans = 0;
            while (lo <= hi) {
                int mid = lo + ((hi - lo) >> 1);
                if (canAchieveWithVec(pathEdges, money, mid)) {
                    ans = mid;
                    lo = mid + 1;
                } else hi = mid - 1;
            }
            cout << ans << '\n';
        }
    }

    return 0;
}

