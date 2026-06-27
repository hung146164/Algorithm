#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll N=1e5+1;

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

namespace sub1
{
bool CheckSub1()
{
    return true;
}
void sol()
{

}
}
namespace sub2
{
bool CheckSub2()
{
    return true;
}
void sol()
{

}
}
namespace sub3
{
bool CheckSub3()
{
    return true;
}
void sol()
{

}
}
typedef pair<ll,ll> pll;
void dijk(vector<vector<ll>>& dist,ll start,vector<vector<pll>>& g)
{
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>>>pq;
    pq.push({0,start});
    while(!pq.empty())
    {
        pair<ll,ll> curr=pq.top();
        pq.pop();
        ll node=curr.second;
        ll val=curr.first;
        for(ll i=0; i< g[node].size(); i++)
        {
            ll to = g[node][i].first;
            ll pus=g[node][i].second;
            if(dist[start][to]<= val+pus) continue;
            dist[start][to]=val+pus;
            pq.push({val+pus,to});
        }
    }
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m,q;
    cin>>n>>m>>q;
    vector<vector<pll>> g(n);
    for(ll i=0; i <m ; i++)
    {
        ll a, b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        g[a].push_back({b,c});

    }
    vector<vector<ll>> dist(n,vector<ll>(n,INT_MAX));
    for(ll i=0; i< n; i++)
    {
        dist[i][i]=0;
    }

    for(ll i=0; i< n; i++)
    {
        dijk(dist,i,g);
    }
//    for(ll i=0; i< dist.size(); i++)
//    {
//        for(ll j=0; j< dist[i].size(); j++)
//        {
//            cout<<dist[i][j]<<' ';
//        }
//        cout<<endl;
//    }
    //dist[0][curr] + dist[child[curr]]
    vector<ll> distskip(n,INT_MAX);
    for(ll u=0; u<n; u++)
    {
        for(ll s=0; s<n; s++)
        {

            for(auto& [to,val]: g[u])
            {
                distskip[s]=min(dist[0][u]+dist[to][s],distskip[s]);
            }
        }
    }
//    for(ll i=0; i< n; i++)
//    {
//        cout<<distskip[i]<<' ';
//    }
//    cout<<'\n';
    while(q--)
    {
        ll a,b;

        cin>>a>>b;
        a--;
        cout<<min(distskip[a]+b,dist[0][a])<<'\n';
    }
}

