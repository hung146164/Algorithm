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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
ll dp[1001][4][4][4][4];
ll sol(ll n, ll a,ll d,ll b,ll c)
{
    if(n<0) return 0;
    if(n==1) return 1;
    if(n==2) return 3;
    if(dp[n][a][b][c][d]!=-1) return dp[n][a][b][c][d];
    ll ans=0;
    ans+=sol(n/2,a,b,c,d);
    ans+=sol(n-n/2,a,c,b,d);
    ans+=sol(1,a,d,b,c);
    ans+=sol(1,c,d,a,b);
    ans+=sol(n-2,b,d,a,c);
    return dp[n][a][b][c][d]=ans;
}
void solve()
{
    memset(dp,-1,sizeof(dp));
    ll n; cin>>n;
    cout<<sol(n,0,3,1,2)<<el;
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









