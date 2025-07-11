#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;
int n;
ll color[N], bb[N];
vector<int> g[N];
int sz[N];
map<ll, ll>* cnt[N];
ll maxFreq[N], sumColor[N];

void getSize(int u, int p) {
    sz[u] = 1;
    for (int v : g[u]) {
        if (v == p) continue;
        getSize(v, u);
        sz[u] += sz[v];
    }
}

void dfs(int u, int p) {
    int big = -1;
    for (int v : g[u]) {
        if (v == p) continue;
        if (big == -1 || sz[v] > sz[big]) big = v;
    }

    for (int v : g[u]) {
        if (v == p || v == big) continue;
        dfs(v, u);
    }

    if (big != -1) {
        dfs(big, u);
        cnt[u] = cnt[big];
        maxFreq[u] = maxFreq[big];
        sumColor[u] = sumColor[big];
    } else {
        cnt[u] = new map<ll, ll>();
    }

    (*cnt[u])[color[u]]++;
    if ((*cnt[u])[color[u]] > maxFreq[u]) {
        maxFreq[u] = (*cnt[u])[color[u]];
        sumColor[u] = color[u];
    } else if ((*cnt[u])[color[u]] == maxFreq[u]) {
        sumColor[u] += color[u];
    }

    for (int v : g[u]) {
        if (v == p || v == big) continue;
        for (auto& [col, freq] : *cnt[v]) {
            (*cnt[u])[col] += freq;
            if ((*cnt[u])[col] > maxFreq[u]) {
                maxFreq[u] = (*cnt[u])[col];
                sumColor[u] = col;
            } else if ((*cnt[u])[col] == maxFreq[u]) {
                sumColor[u] += col;
            }
        }
    }

    bb[u] = sumColor[u];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> color[i];
    for (int i = 1; i < n; ++i) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    getSize(1, -1);
    dfs(1, -1);

    for (int i = 1; i <= n; ++i) cout << bb[i] << " ";
    cout << '\n';
}
