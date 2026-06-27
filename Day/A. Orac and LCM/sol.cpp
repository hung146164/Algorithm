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
const ll N=2e5+5;
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
ll gcd(ll a,ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
ll lcm(ll a, ll b)
{
    return a*b/gcd(a,b);
}
ll mnt[N];
void sang()
{
    mnt[1]=1;
    for(ll i=2; i<N; i++)
    {
        if(mnt[i]==0)
        {
            for(ll j=i; j<N; j+=i)
            {
                if(mnt[j]==0) mnt[j]=i;
            }
        }
    }
}
void solve()
{
    sang();
    ll n;
    cin>>n;
    vector<ll> nums(n);
    for(ll i=0; i< n; i++) cin>>nums[i];
    unordered_map<ll,vector<ll>> dp;
    for(ll i=0; i< n; i++)
    {
        ll clone=nums[i];

        unordered_map<ll,ll> cnt;
        while(clone!=1)
        {
            cnt[mnt[clone]]++;
            clone/=mnt[clone];
        }
        for(auto& j: cnt)
        {
            dp[j.first].push_back(j.second);
        }
    }
    ll ans=1;
    for(auto& i : dp)
    {
        sort(i.second.begin(),i.second.end());
//        cout<<i.first<<": ";

        vector<ll> c=i.second;
//        for(ll j=0; j< c.size(); j++)
//        {
//            cout<<c[j]<<' ';
//        }
//        cout<<el;
        if(c.size()==n)
        {
            for(ll j=0; j<c[1];j++)
            {
                ans*=i.first;
            }
        }
        else if(c.size()==n-1) {
            for(ll j=0;j<c[0];j++)
            {
                ans*=i.first;
            }
        }
    }
    cout<<ans<<el;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll t;
    t=1;
    while(t--)
    {
        solve();
    }
}









