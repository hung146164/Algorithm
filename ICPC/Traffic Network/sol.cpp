#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll N=1e5+1;
const ll INF=1e18;
struct edge
{
    ll to,val;
    bool haichieu;
    edge(ll a,ll b, bool c) : to(a),val(b),haichieu(c) {}
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m,k,s,t;
        cin>>n>>m>>k>>s>>t;
        vector<vector<edge>> g(n+1);
        for(ll i=0; i< m ; i++)
        {
            ll a, b,c;
            cin>>a>>b>>c;
            g[a].push_back(edge(b,c,false));
        }
        for(ll i=0; i< k; i++)
        {
            ll a, b,c;
            cin>>a>>b>>c;
            g[a].push_back(edge(b,c,true));
            g[b].push_back(edge(a,c,true));
        }
        priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>> pq;
        //val, curr, have
        vector<vector<ll>> dist(n+1,vector<ll>(2,INF));
        pq.push({0,s,0});
        while(!pq.empty())
        {
            vector<ll> curr=pq.top();
            pq.pop();
            for(ll i=0; i< g[curr[1]].size(); i++)
            {
                edge to=g[curr[1]][i];
                if(to.haichieu && curr[2]==1) continue;
                if(dist[to.to][curr[2]]<= to.val+curr[0]) continue;
                dist[to.to][curr[2]]=to.val+curr[0];
                pq.push({to.val+curr[0],to.to,to.haichieu+curr[2]});
            }
        }
        ll ans=min(dist[t][0],dist[t][1]);
        cout<<(ans==INF?-1:ans)<<'\n';
    }

}
