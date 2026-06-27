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
const ll N=75;
const ll mod=1e9+7;
const ll modr=1e9+9;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
using i128 = __int128;
constexpr i64 inf = 1E18;

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
ll nums[N][N];
ll dp[N][N][N][N];
ll n,m,k;
ll sol(ll i,ll j,ll rem,ll x,ll& k)
{
    if(i==n)
    {
        if(x==0) return 0;
        return INT_MIN;
    }
    if(dp[i][j][rem][x]!=-inf) return dp[i][j][rem][x];
    ll ans=INT_MIN;
    if(rem<m/2 && j<m)
    {
        ans=max(ans,sol(i,j+1,rem,x,k));
        ans=max(ans,nums[i][j]+sol(i,j+1,rem+1,(x+nums[i][j])%k,k));
    }
    else{

        ans=max(ans,sol(i+1,0,0,x,k));
    }


    return dp[i][j][rem][x]=ans;

}
void solve()
{
    cin>>n>>m>>k;
    for(ll i=1; i<=n; i++)
    {
        for(ll j=1; j<=m; j++)
        {
            cin>>nums[i][j];
        }
    }
    ll ans=0;

    cout<<ans<<'\n';
    //cout<<sol(0,0,0,0,k)<<el;

}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
//    for(int i=0; i<N; i++)
//    {
//        for(int j=0; j<N; j++)
//        {
//            for(int k=0; k<N; k++)
//            {
//                for(int z=0;z<N; z++)
//                {
//                    dp[i][j][k][z]=-inf;
//                }
//            }
//        }
//    }
    ll t;
    t=1;
    while(t--)
    {
        solve();
    }
}










