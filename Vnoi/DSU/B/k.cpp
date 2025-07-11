#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class DSU
{
    public:
    vector<ll> parent,LEN;
    DSU(ll n)
    {
        parent.resize(n+1);LEN.resize(n+1);
        for(ll i=0; i<=n;i++)
        {
            parent[i]=i;
            LEN[i]=1;
        }
    }
    ll fin(ll a)
    {
        if(a==parent[a]) return a;
        return parent[a]=fin(parent[a]);
    }
    void smalltolarge(ll a, ll b)
    {
        LEN[a]+=LEN[b];
        parent[b]=a;
    }
    void join(ll a, ll b)
    {
        ll pa=fin(a),pb=fin(b);
        if(pa==pb) return ;
        if(LEN[pa]<LEN[pb])
        {
            smalltolarge(pb,pa);
        }
        else{
            smalltolarge(pa,pb);
        }
    }
};
ll sol(vector<vector<ll>>& e, ll curr,ll n)
{
    DSU dsu(n);
    ll edge=0;
    ll ans=LLONG_MIN;
    for(ll i=curr; i<e.size(); i++)
    {
        if(dsu.fin(e[i][1])==dsu.fin(e[i][2])) continue;
        dsu.join(e[i][1],e[i][2]);
        edge++;
        ans=max(ans,e[i][0]);

    }
    if(edge==n-1) return ans-e[curr][0];
    return LLONG_MAX;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m; cin>>n>>m;
    vector<vector<ll>> e(m,vector<ll>(3,0));

    for(int i=0; i< m ; i++)
    {
        cin>>e[i][1]>>e[i][2]>>e[i][0];
    }
    ll ans=LLONG_MAX;
    sort(e.begin(),e.end());
    for(ll i=0; i< e.size(); i++)
    {
        ans=min(ans,sol(e,i,n));
    }
    if (ans == LLONG_MAX) cout << "NOT FOUND\n";
    else cout << ans << '\n';

}
