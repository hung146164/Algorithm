/*
    Author: HungForree
    Link: https://codeforces.com/contest/803/problem/F
*/

#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
const ll N=1e5+5;
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
ll cnt[N];
ll f[N];
ll pow2[N];
ll dp[N];
void process()
{
    pow2[0]=1;
    for(ll i=1; i<N; i++)
    {
        pow2[i]=pow2[i-1]*2%mod;
    }
}
void solve()
{
    process();
    ll n; cin>>n;
    for(ll i=0 ;i< n; i++)
    {
        ll x; cin>>x;
        cnt[x]++;
    }

    for(ll i=1; i<N; i++)
    {
        for(ll j=i; j<N; j+=i)
        {
            f[i]=(f[i]+cnt[j])%mod;
        }
    }
//    for(ll i=0; i< 20; i++)
//    {
//        cout<<f[i]<<' ';
//    }
//    cout<<el;
    for(ll i=N-1;i>=1; i--)
    {
        dp[i]=pow2[f[i]]-1;
        for(ll j=2*i; j<N; j+=i)
        {
            dp[i]=(dp[i]-dp[j]+mod)%mod;
        }
    }
    cout<<dp[1]<<el;
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









