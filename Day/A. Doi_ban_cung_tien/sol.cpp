/*
    Author: HungForree
    Link: https://codeforces.com/group/1ow7dngTMQ/contest/669095/problem/A
*/

#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
const ll N=1e6+5;
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
ll gt[N],ingt[N];
ll powll(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a%mod;
        }
        a=a*a%mod;
        b/=2;
    }
    return ans;
}
void process()
{
    gt[0]=ingt[0]=1;
    for(ll i=1; i<N; i++)
    {
        gt[i]=gt[i-1]*i%mod;
        ingt[i]=ingt[i-1]*powll(i,mod-2)%mod;
    }
}
ll C(ll n, ll k)
{
    if(k>n) return 0;
    return (gt[n]*ingt[n-k]%mod)*ingt[k]%mod;
}
void solve()
{

    ll n; cin>>n;
    vector<ll> nums(n);
    for(ll i=0; i< n; i++)
    {
        cin>>nums[i];
    }
    ll sum=0;
    ll ans=0;
    for(ll i=0; i< nums.size(); i++)
    {
        sum+=nums[i];
    }
    for(int i=0; i< n; i++)
    {
        ans=(ans+(sum-nums[i])*nums[i]%mod)%mod;
    }
    //cout<<(C(sum,2)-diff+mod)%mod<<el;
    cout<<ans*powll(2,mod-2)%mod<<el;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    //process();
    ll t; t=1;
    while(t--)
    {
        solve();
    }
}









