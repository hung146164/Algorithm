#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll N=1e5+1;
const ll INF = LLONG_MAX / 4;
ll xuoi[N];
ll nguoc[N];
ll t3[N];
ll minll(ll a,ll b)
{
    if(a>b) return b;
    else return a;
}
void shortpathxuoi(ll start,vector<vector<pair<ll,ll>>>& g)
{
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    xuoi[start]=0;
    pq.push({0,start});
    while(!pq.empty())
    {
        pair<ll,ll> curr=pq.top();
        ll val=curr.first;
        ll ht=curr.second;
        pq.pop();
        for(ll i=0; i<g[ht].size(); i++)
        {
            ll to=g[ht][i].first;
            ll gia=g[ht][i].second;
            if(gia+val>=xuoi[to]) continue;
            xuoi[to]=gia+val;
            pq.push({gia+val,to});
        }
    }
}
void shortpathnguoc(ll start,vector<vector<pair<ll,ll>>>& g)
{
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    nguoc[start]=0;
    pq.push({0,start});
    while(!pq.empty())
    {
        pair<ll,ll> curr=pq.top();
        ll val=curr.first;
        ll ht=curr.second;
        pq.pop();
        for(ll i=0; i<g[ht].size(); i++)
        {
            ll to=g[ht][i].first;
            ll gia=g[ht][i].second;
            if(gia+val>=nguoc[to]) continue;
            nguoc[to]=gia+val;
            pq.push({gia+val,to});
        }
    }
}
void shortpathnguoc2(ll start,vector<vector<pair<ll,ll>>>& g)
{
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    t3[start]=0;
    pq.push({0,start});
    while(!pq.empty())
    {
        pair<ll,ll> curr=pq.top();
        ll val=curr.first;
        ll ht=curr.second;
        pq.pop();
        for(ll i=0; i<g[ht].size(); i++)
        {
            ll to=g[ht][i].first;
            ll gia=g[ht][i].second;
            if(gia+val>=t3[to]) continue;
            t3[to]=gia+val;
            pq.push({gia+val,to});
        }
    }
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fill(xuoi,xuoi+N,INF);
    fill(nguoc,nguoc+N,INF);
    fill(t3,t3+N,INF);

    ll n,m,k,x;cin>>n>>m>>k>>x;
    vector<vector<pair<ll,ll>>> gxuoi(n+1);
    vector<vector<pair<ll,ll>>> gnguoc(n+1);
    vector<vector<pair<ll,ll>>> gg(n+1);
    for(ll i=0; i< m ;i++)
    {
        ll a,b,c,d; cin>>a>>b>>c>>d;
        gxuoi[a].push_back({b,d});
        gnguoc[b].push_back({a,c});
        gg[b].push_back({a,d});
    }
    shortpathxuoi(1,gxuoi);
    shortpathnguoc(k,gnguoc);
    shortpathnguoc2(n,gg);
    //ll ans=INF;
//    for(ll i=1; i<=n; i++)
//    {
//        cout<<xuoi[i]<<' ';
//    }
//    cout<<'\n';
//    for(ll i=1; i<=n;i++)
//    {
//        cout<<nguoc[i]<<' ';
//    }
//    cout<<'\n';
//        for(ll i=1; i<=n;i++)
//    {
//        cout<<t3[i]<<' ';
//    }
//    cout<<'\n';
    ll ans=INF;
    for(ll i=1; i<=n; i++)
    {
        if(xuoi[i]+nguoc[i]<=x)
        {
            ans=minll(ans,xuoi[i]+t3[i]);
            //cout<<i<<' '<<xuoi[i]+t3[i]<<'\n';
        }
    }
    cout<<(ans==INF?-1:ans)<<'\n';
}


