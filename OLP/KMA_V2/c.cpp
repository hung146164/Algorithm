#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll N=1e5+1;
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
ll parent[N];
ll len[N];
ll find(ll p)
{
    if(p==parent[p])
    {
        return p;
    }
    return find(parent[p]);
}
void process(ll n)
{
    for(ll i=0; i<=n; i++)
    {
        parent[i]=i;
        len[i]=1;
    }
}
void join(ll a, ll b)
{
    ll pa=find(a);
    ll pb=find(b);
    if(pa==pb) return;
    if(len[pa]>len[pb])
    {
        parent[pb]=pa;
        len[pa]+=len[pb];
    }
    else{
        parent[pa]=pb;
        len[pb]+=len[pa];
    }
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m; cin>>n>>m;
    process(n);

    vector<vector<pair<ll,ll>>> g(n+1);
    priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>> pq;
    vector<bool> check(n+1);
    for(ll i=0; i< m; i++)
    {
        ll a, b, c; cin>>a>>b>>c;
        pq.push({c,a,b});
    }
    ll ans=0;
    while(!pq.empty())
    {
        vector<ll> curr=pq.top();
        pq.pop();

        ll val=curr[0];
        ll a=curr[1];
        ll b=curr[2];

        //cout<<a<<' '<<b<<'\n';

        ans+=val;
        join(a,b);

        if(len[find(a)]==n) break;

        //cout<<a<<' '<<b<<' '<<(len[find(a)])<<'\n';

    }
    if(len[find(1)]!=n) cout<<-1<<'\n';
    else cout<<ans<<'\n';

}



