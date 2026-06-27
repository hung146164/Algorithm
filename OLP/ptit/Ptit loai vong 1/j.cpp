#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6 + 5;

map<char, char> mp, revMp;

inline void prepare() {
    mp['('] = ')';
    mp['['] = ']';
    mp['{'] = '}';

    revMp[')'] = '(';
    revMp[']'] = '[';
    revMp['}'] = '{';
}

int n, res;
string s;
vector<int> adj[maxN];
stack<char> tmp;

void dfs(int u, int p) {
    if (mp.count(s[u])) {
        tmp.push(s[u]);
    } else {
        if (!tmp.empty() && mp[tmp.top()] == s[u]) {
            tmp.pop();
        } else {
            return;
        }
    }

    if (tmp.empty()) {
        res++;
    }

    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
    }

    // backtrack
    if (mp.count(s[u])) {
        tmp.pop();
    } else {
        tmp.push(revMp[s[u]]);
    }
}

void solve() {
    cin >> n;
    cin >> s;
    s = '#' + s; // để index từ 1

    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        dfs(i, 0);
        cout<<res<<'\n';
    }

    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    prepare();

    int Case = 1;
    // cin >> Case;
    while (Case--) {
        solve();
    }
    return 0;
}

