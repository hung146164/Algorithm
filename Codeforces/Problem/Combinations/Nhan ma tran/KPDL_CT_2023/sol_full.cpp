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
vector<vector<ll>> mul(vector<vector<ll>>& a, vector<vector<ll>>& b)
{
    ll n=a.size();
    ll m=b.size();
    vector<vector<ll>> ans(n,vector<ll>(m));
    for(ll i=0; i< n; i++)
    {
        for(ll j=0; j< m; j++)
        {
            for(ll k=0; k< n ;k++)
            {
                ans[i][j]=(ans[i][j]+(a[i][k]*b[k][j]%mod) )%mod;
            }
        }
    }
    return ans;
}
vector<vector<ll>> power(vector<vector<ll>>& base, ll b,vector<vector<ll>>& dv)
{
    vector<vector<ll>> res=dv;
    while(b)
    {
        if(b&1)
        {
            res=mul(res,base);
        }
        b/=2;
        base=mul(base,base);
    }
    return res;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k; cin>>n>>k;
    vector<vector<ll>> base(k,vector<ll>(k));
    vector<vector<ll>> dv(k,vector<ll>(k));

    for(ll i=0; i<k ;i++)
    {
        base[i][i]=1;
        base[i][(i-1+k)%k]=3;
        base[i][(i-2+k)%k]=3;
        dv[i][i]=1;
    }

    vector<vector<ll>> ans= power(base,n,dv);
    cout<<ans[0][0]-1<<'\n';
}

