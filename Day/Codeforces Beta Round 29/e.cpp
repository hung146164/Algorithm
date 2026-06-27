#include <bits/stdc++.h>
using namespace std;

#define el '\n'
const int N = 505;

vector<int> g[N];
int dist[2][N][N]; // dist[lượt][vị trí Bob][vị trí Alex]

// Dùng struct để lưu trạng thái truy vết cho gọn
struct State {
    int t, u, v;
};
State parent_state[2][N][N];

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    memset(dist, -1, sizeof(dist));
    queue<State> q;

    // t = 0 nghĩa là đang ở mốc thời gian chẵn, đến lượt Bob đi trước
    q.push({0, 1, n});
    dist[0][1][n] = 0;

    bool found = false;
    while (!q.empty()) {
        State curr = q.front();
        q.pop();

        int t = curr.t;
        int a = curr.u;
        int b = curr.v;

        // Nếu cả 2 đã hoàn thành 1 bước đi (t = 0) và cùng đến đích
        if (t == 0 && a == n && b == 1) {
            found = true;
            break;
        }

        if (t == 0) {
            // Nửa bước 1: Lượt của Bob đi từ đỉnh 'a' sang đỉnh 'u'
            for (int u : g[a]) {
                if (dist[1][u][b] == -1) {
                    dist[1][u][b] = dist[0][a][b] + 1;
                    parent_state[1][u][b] = curr;
                    q.push({1, u, b});
                }
            }
        } else {
            // Nửa bước 2: Lượt của Alex đi từ đỉnh 'b' sang đỉnh 'v'
            for (int v : g[b]) {
                // Kiểm tra luật: Sau khi Alex đi, 2 người không được ở chung nút
                if (a == v) continue;

                if (dist[0][a][v] == -1) {
                    dist[0][a][v] = dist[1][a][b] + 1;
                    parent_state[0][a][v] = curr;
                    q.push({0, a, v});
                }
            }
        }
    }

    if (!found) {
        cout << -1 << el;
        return;
    }

    // Truy vết lại bằng vòng lặp an toàn tuyệt đối
    vector<int> path_a, path_b;
    State curr = {0, n, 1};

    while (true) {
        // Chỉ ghi nhận vị trí khi cả 2 đã hoàn thành trọn vẹn 1 bước (t = 0)
        if (curr.t == 0) {
            path_a.push_back(curr.u);
            path_b.push_back(curr.v);
        }

        // Điều kiện dừng chính xác 100%
        if (curr.t == 0 && curr.u == 1 && curr.v == n) break;

        curr = parent_state[curr.t][curr.u][curr.v];
    }

    // Đảo ngược lộ trình
    reverse(path_a.begin(), path_a.end());
    reverse(path_b.begin(), path_b.end());

    // In kết quả
    cout << path_a.size() - 1 << el;
    for (int i = 0; i < path_a.size(); i++) cout << path_a[i] << (i == path_a.size() - 1 ? "" : " ");
    cout << el;
    for (int i = 0; i < path_b.size(); i++) cout << path_b[i] << (i == path_b.size() - 1 ? "" : " ");
    cout << el;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
