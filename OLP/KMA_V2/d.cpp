#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=1e5+1;
const ll inf=LLONG_MAX/4;
ll maxll(ll a,ll b)
{
    if(a>b) return a;
    return b;
}
ll minll(ll a,ll b)
{
    if(a>b) return b;
    return a;
}
ll gdc(ll a, ll b)
{
    if(b==0) return a;
    return gdc(b,a%b);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m; cin>>n>>m;
    ll a, b; cin>>a>>b;
    vector<vector<pair<ll,ll>>> g(n+1);
    for(ll i=0; i< m ;i++)
    {
        ll a, b,c; cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,a});
    vector<ll> dist(n+1,inf);
    while(!pq.empty())
    {
        pair<ll,ll> curr=pq.top();
        pq.pop();

        ll ht=curr.second;
        ll val=curr.first;

        if(dist[ht]<val) continue;
        dist[ht]=val;

        for(ll i=0; i< g[ht].size(); i++)
        {
            ll to=g[ht][i].first;
            ll gia=g[ht][i].second;
            if(dist[to]>val+gia)
            {
                pq.push({val+gia,to});
            }
        }
    }
    cout<<(dist[b]==inf?-1:dist[b])<<'\n';
}



