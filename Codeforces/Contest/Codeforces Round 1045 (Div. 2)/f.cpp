#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9 + 7;

const int N = 55;

vector<ll> memo[N][N][N][N][4];
bool vis[N][N][N][N][4];

int cost[4][4] = {
    {0, 1, 2, 1},
    {1, 0, 1, 2},
    {2, 1, 0, 1},
    {1, 2, 1, 0}
};

vector<ll> add(const vector<ll>& p1, const vector<ll>& p2) {
    int n = max((int)p1.size(), (int)p2.size());
    vector<ll> ans(n);
    for (int i = 0; i < n; ++i) {
        ll v1 = (i < (int)p1.size()) ? p1[i] : 0;
        ll v2 = (i < (int)p2.size()) ? p2[i] : 0;
        ans[i] = (v1 + v2) % mod;
    }
    return ans;
}

vector<ll> change(const vector<ll>& p, int k) {
    if (p.empty() || (p.size() == 1 && p[0] == 0)) return {0};
    vector<ll> ans(p.size() + k, 0);
    for (int i = 0; i < (int)p.size(); ++i) ans[i + k] = p[i];
    return ans;
}


vector<ll> sol(int a, int b, int c, int d, int last) {
    if (vis[a][b][c][d][last]) return memo[a][b][c][d][last];
    vis[a][b][c][d][last] = true;

    int total = a + b + c + d;
    if (total == 0) return memo[a][b][c][d][last] = {0};

    if (total == 1) {
        vector<ll> ans;
        if ((last == 0 && a == 1) || (last == 1 && b == 1) || (last == 2 && c == 1) || (last == 3 && d == 1))
            ans = {1};
        else
            ans = {0};
        return memo[a][b][c][d][last] = ans;
    }

    vector<ll> curr = {0};
    for (int prev = 0; prev < 4; ++prev) {
        int na = a, nb = b, nc = c, nd = d;
        if (last == 0) na--;
        else if (last == 1) nb--;
        else if (last == 2) nc--;
        else nd--;
        if (na < 0 || nb < 0 || nc < 0 || nd < 0) continue;

        vector<ll> pre = sol(na, nb, nc, nd, prev);
        int cst = cost[prev][last];
        curr = add(curr, change(pre, cst));
    }
    return memo[a][b][c][d][last] = curr;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int c[4], n = 0;
        for (int i = 0; i < 4; ++i) {
            cin >> c[i];
            n += c[i];
        }
        vector<ll> ans = {0};
        for (int last = 0; last < 4; ++last) {
            if (c[last] > 0) {
                vector<ll> res = sol(c[0], c[1], c[2], c[3], last);
                ans = add(ans, res);
            }
        }
        for (int k = 0; k <= 2 * (n - 1); ++k) {
            if (k < (int)ans.size()) cout << ans[k];
            else cout << 0;
            if (k != 2 * (n - 1)) cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}
