#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int x, y, z, t;
    cin >> x >> y >> z >> t;


    x--; y--; z--; t--;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];


    unordered_map<int, vector<pair<int,int>>> pos;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != 0) {
                pos[a[i][j]].push_back({i, j});
            }
        }
    }

    vector<vector<int>> dist(n, vector<int>(m, INF));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    unordered_map<int, bool> used;

    queue<pair<int,int>> q;
    q.push({x, y});
    dist[x][y] = 0;
    visited[x][y] = true;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [u, v] = q.front(); q.pop();


        if (u == z && v == t) {
            cout << dist[u][v];
            return 0;
        }


        for (int k = 0; k < 4; k++) {
            int nu = u + dx[k];
            int nv = v + dy[k];

            if (nu >= 0 && nu < n && nv >= 0 && nv < m) {
                if (!visited[nu][nv] && a[nu][nv] != 0) {
                    visited[nu][nv] = true;
                    dist[nu][nv] = dist[u][v] + 1;
                    q.push({nu, nv});
                }
            }
        }


        int val = a[u][v];
        if (val != 0 && !used[val]) {
            for (auto [i, j] : pos[val]) {
                if (!visited[i][j]) {
                    visited[i][j] = true;
                    dist[i][j] = dist[u][v] + 1;
                    q.push({i, j});
                }
            }
            used[val] = true;


            pos[val].clear();
        }
    }


    cout << -1;
    return 0;
}
