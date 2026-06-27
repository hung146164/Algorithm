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
vector<vector<ll>> child(100);
vector<vector<ll>> parent(100);
vector<vector<ll>> mul(vector<vector<ll>>& a, vector<vector<ll>>& b)
{
    ll n=a.size(),m=b.size();
    vector<vector<ll>> ans(n,vector<ll>(m));
    for(ll i=0; i< n; i++)
    {
        for(ll j=0; j< m ;j++)
        {
            for(ll k=0; k< n; k++)
            {
                ans[i][j]=(ans[i][j]+a[i][k]*b[k][j]%mod)%mod;
            }
        }
    }
    return ans;
}
vector<vector<ll>> power(vector<vector<ll>>& base,ll b, vector<vector<ll>>& dv)
{
    vector<vector<ll>> ans=dv;
    while(b)
    {
        if(b&1)
        {
            ans=mul(ans,base);
        }
        b/=2;
        base=mul(base,base);
    }
    return ans;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m,k;
    cin>>n>>m>>k;

    for(ll i=0; i< m ; i++)
    {
        ll a, b;
        cin>>a>>b;
        a--;
        b--;
        child[a].push_back(b);
        parent[b].push_back(a);
    }
    vector<vector<ll>> base(n,vector<ll> (n));
    vector<vector<ll>> dv(n,vector<ll>(n));
    for(ll i=0; i< n; i++) dv[i][i]=1;
    for(ll i=0; i< n; i++)
    {
        for(ll j=0; j< child[i].size(); j++)
        {
            base[i][child[i][j]]++;
        }
    }
//    for(ll i=0; i< base.size(); i++)
//    {
//        for(ll j=0; j< base[i].size(); j++)
//        {
//            cout<<base[i][j]<<' ';
//        }
//        cout<<'\n';
//    }
//    cout<<'\n';
    vector<vector<ll>> ans=power(base,k,dv);
//    for(ll i=0; i< ans.size(); i++)
//    {
//        for(ll j=0; j< ans.size(); j++)
//        {
//            cout<<ans[i][j]<<' ';
//        }
//        cout<<'\n';
//    }
    cout<<ans[0][n-1]<<'\n';

}


