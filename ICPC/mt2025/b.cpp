#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll N=1e5+1;

ll Xor[N];
ll kq[N];
void sol(ll curr, vector<vector<pair<ll,ll>>>& g,ll kq=0,ll p=-1)
{

    Xor[curr]=kq;
    for(ll i=0; i<g[curr].size(); i++)
    {
        if(g[curr][i].first!=p)
        {
            sol(g[curr][i].first,g,kq^g[curr][i].second,curr);
        }
    }
}
ll powll(ll a, ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
        {
            ans*=a;
        }
        a*=a;
        b/=2;
    }
    return ans;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin>>n;

    vector<vector<pair<ll,ll>>>g(n+1);
    for(ll i=0; i< n-1; i++)
    {
        ll a, b, c;cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    sol(1,g);
    vector<vector<ll>> dem(32,vector<ll>(2,0));
    for(ll i=1; i<=n; i++)
    {
        for(ll j=31; j>=0; j--)
        {
            dem[j][((Xor[i]>>j) & 1)]++;
        }
    }

    ll ans=0;
    for(ll i=0; i< dem.size(); i++)
    {
        ans+=dem[i][0]*dem[i][1]*powll(2,i);
    }
    cout<<ans<<'\n';
    // 4 1 2 3 2 3 5 2 4 6
}


