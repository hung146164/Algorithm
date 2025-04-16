#include <bits/stdc++.h>
using namespace std;

int n,b;
vector<pair<int, int>> cows;

int solve(int px, int py) {
    int quad[2][2] = {}; // quad[0][0]: bên trái dưới, quad[0][1]: bên trái trên, quad[1][0]: bên phải dưới, quad[1][1]: bên phải trên
    for (pair<int, int> i : cows) {
        int cx = i.first > px;  // nếu i.first > px → thuộc bên phải (1), ngược lại bên trái (0)
        int cy = i.second > py; // nếu i.second > py → thuộc phía trên (1), ngược lại phía dưới (0)
        quad[cx][cy]++;
    }
    return max({quad[0][0], quad[0][1], quad[1][0], quad[1][1]});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);

    cin >> n>>b;
    cows.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> cows[i].first >> cows[i].second;
    }

    int res = n;
    for (int i = 0; i < n; ++i) {             // vòng lặp bên ngoài
        for (int j = 0; j < n; ++j) {         // vòng lặp bên trong
            int val = solve(cows[i].first + 1, cows[j].second + 1);
            res = min(res, val);
        }
    } // <-- đóng vòng lặp bên ngoài

    cout << res << '\n';
    return 0;
}
