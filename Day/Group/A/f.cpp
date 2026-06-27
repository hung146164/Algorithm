/*
    Author: HungForree
    Link:
*/

#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
const ll N=5e5+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
using i128 = __int128;
constexpr i64 inf = 1E18;
vector<vector<ll>> mul(vector<vector<ll>>& a, vector<vector<ll>>& b)
{
    ll n=a.size();
    ll m=b[0].size();

    ll z=a[0].size();
    vector<vector<ll>> ans(n,vector<ll>(m));
    for(ll i=0; i< n; i++)
    {
        for(ll j=0; j<m; j++)
        {
            for(ll k=0; k<z; k++)
            {
                ans[i][j]=(ans[i][j]+a[i][k]*b[k][j]%mod)%mod;
            }
        }
    }
    return ans;
}
vector<vector<ll>> power(vector<vector<ll>>& base, ll b, vector<vector<ll>> dv)
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

void solve()
{
    string s; cin>>s;
    reverse(s.begin(),s.end());
    ll n=0;
    for(int i=0; i< s.size(); i++)
    {
        if(s[i]=='1') n+=(1LL<<i);
    }

    vector<vector<ll>> base{
        {
            0,1,1,0,1,0,0,0
        },
        {
            1,0,0,1,0,1,0,0
        },
        {
            1,0,0,1,0,0,1,0
        },
        {
            0,1,1,0,0,0,0,1
        },
        {
            1,0,0,0,0,1,1,0
        },
        {
            0,1,0,0,1,0,0,1
        },
        {
            0,0,1,0,1,0,0,1
        },
        {
            0,0,0,1,0,1,1,0
        }
    };
    vector<vector<ll>> dv(8,vector<ll>(8,0));
    for(ll i=0; i< 8; i++)
    {
        dv[i][i]=1;
    }
    vector<vector<ll>> ans= power(base,n,dv);
//    for(int i=0; i< ans.size(); i++)
//    {
//        for(int j=0; j< ans[0].size(); j++)
//        {
//            cout<<ans[i][j]<<' ';
//        }
//        cout<<el;
//    }
    cout<<ans[0][7]<<el;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll t; t=1;
    while(t--)
    {
        solve();
    }
}
