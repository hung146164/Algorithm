#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
ll nhanando(ll a, ll b)
{
    ll ans=0;
    while(b)
    {
        if(b&1)
        {
            ans=(ans+a)%mod;
        }
        a=a*2%mod;
        b/=2;
    }
    return ans;
}
vector<vector<ll>> mul(vector<vector<ll>>& a, vector<vector<ll>>& b)
{
    ll n=a.size();
    ll m=b.size();
    vector<vector<ll>> ans(n,vector<ll>(m));
    for(ll i=0; i< n; i++)
    {
        for(ll j=0; j< m; j++)
        {
            for(ll k=0; k< n; k++)
            {
                ans[i][j]=(ans[i][j]+nhanando(a[i][k],b[k][j]))%mod;
            }
        }
    }
    return ans;
}

vector<vector<ll>> power(vector<vector<ll>>& base, vector<vector<ll>> dv, ll b)
{
    vector<vector<ll>> ans=dv;
    while(b)
    {
        if(b&1)
        {
            ans=mul(ans,base);
        }
        base=mul(base,base);
        b/=2;
    }
    return ans;
}
ll gdc(ll a,ll b)
{
    if(b==0) return a;
    return gdc(b,a%b);
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, b,c ; cin>>a>>b>>c;
    mod=c;
    ll time=gdc(a,b);
    vector<vector<ll>> base={{0,1},{1,1}};
    vector<vector<ll>>  dv={{1,0},{0,1}};

    vector<vector<ll>> ans=power(base,dv,time);

    cout<<ans[0][1]<<'\n';
}


