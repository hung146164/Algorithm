#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
const ll N=1e5+1;

vector<vector<ll>> mtdv{{1,0},{0,1}};
vector<vector<ll>> base{{0,1},{1,1}};

void debug(ll i)
{
    cout<<"Debug"<<' '<<i<<endl;
}
ll mul_ando(ll a, ll b, ll m)
{
    ll ans=0;
    while(b)
    {
        if(b&1)
        {
            ans=(ans+a)%m;
        }
        b/=2;
        a=(a*2)%m;
    }
    return ans;
}
vector<vector<ll>> mul(vector<vector<ll>>& a, vector<vector<ll>>& b)
{
    vector<vector<ll>> ans(a.size(),vector<ll>(b.size()));
    //debug(0);
    for(ll i=0; i< a.size(); i++)
    {
        for(ll j=0; j< b.size(); j++)
        {
            for(ll k=0; k< a.size(); k++)
            {
                ll prod = mul_ando(a[i][k], b[k][j], mod);
                ans[i][j] = (ans[i][j] + prod) % mod;
            }
        }
    }
    return ans;
}
vector<vector<ll>> power(vector<vector<ll>> a, ll p)
{
    vector<vector<ll>> ans=mtdv;
    while(p)
    {
        if(p&1)
        {
            ans=mul(ans,a);
        }
        p/=2;
        a=mul(a,a);
    }
    return ans;
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
    ll a, b,m; cin>>a>>b>>m;
    mod=m;
    vector<vector<ll>> base{{0,1},{1,1}};
    vector<vector<ll>> cc=power(base,gdc(a,b)-1);
    cout<<cc[1][1]<<'\n';
}

