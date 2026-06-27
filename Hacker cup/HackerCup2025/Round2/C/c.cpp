#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = LLONG_MAX/4;
const ll mod=1e9+7;

ll n, k, m;
vector<vector<ll>> rou;
vector<vector<pair<ll,ll>>> occ;
vector<vector<ll>> parent;

int find(int rid, int x) {
    int sz = (int)parent[rid].size();
    if (x >= sz) return x;
    int curr = x;
    while (curr < sz && parent[rid][curr] != curr) curr = parent[rid][curr];
    int node = x;
    while (node < sz && parent[rid][node] != node) {
        int nxt = parent[rid][node];
        parent[rid][node] = curr;
        node = nxt;
    }
    return curr;
}

vector<ll> cal() {
    vector<ll> dist(n+1, INF);
    dist[1] = 0;
    queue<ll> q;
    q.push(1);

    parent.assign(m, {});
    for(ll i = 0; i < m; ++i)
    {
        ll len = rou[i].size();
        parent[i].resize(len+1);
        for(ll j = 0; j <= len; j++) parent[i][j] = j;
    }

    while(!q.empty()){
        ll curr = q.front(); q.pop();
        ll kc = dist[curr];

        for(pair<ll,ll>& p : occ[curr])
        {
            ll val = p.first;
            ll to = p.second;

            ll len = rou[val].size();
            ll l = to + 1;
            if(l >= len) continue;
            ll r = min(len-1, to + k);

            ll i = find(val, l);
            while(i <= r)
            {
                parent[val][i] = find(val, i + 1);
                ll v = rou[val][i];
                if(dist[v] == INF){
                    dist[v] = kc + 1;
                    q.push(v);
                }
                i = find(val, i);
            }
        }
    }

    return dist;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("designing_paths_input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    ll t;
    cin >> t;

    for(ll z = 1; z <= t; ++z)
    {
        cin >> n >> k >> m;
        rou.assign(m, {});
        occ.assign(n+1, {});

        for(ll i = 0; i < m; i++)
        {
            ll len;
            cin >> len;
            for(ll j = 0; j < len; j++){
                ll x;
                cin >> x;
                rou[i].push_back(x);
                occ[x].push_back({i, j});
            }
        }

        vector<ll> dist = cal();
        ll ans = 0;

        for(ll i = 1; i <= n; i++)
        {
            if(dist[i] == INF) ans += -i;
            else ans += dist[i] * i;
        }

        cout << "Case #" << z << ": " << ans << "\n";
    }

    return 0;
}
