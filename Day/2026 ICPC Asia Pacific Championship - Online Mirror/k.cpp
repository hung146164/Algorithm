/*
    Author: HungForree
    Link: https://codeforces.com/contest/2206/problem/K
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
bool check (ll m, vector<ll>& cnt)
{
    ll sum_0_5 = 0;
    for (ll i = 0; i <= 5; ++i) {
        sum_0_5 += cnt[i];
    }

    ll x = max(0LL, m - cnt[0]);

    ll y = m;
    y = min(y, cnt[1]);
    y = min(y, cnt[0] + cnt[1] - m);
    y = min(y, sum_0_5-1LL*2*m);

    return x <= y;
}
void solve()
{
    ll n; cin>>n;
    string s; cin>>s;
    vector<ll> cnt(10);
    for(ll i=0; i< n; i++)
    {
        cnt[s[i]-'0']++;
    }
    ll l=0, r=n/4;
    ll ans=0;

    while(l<=r)
    {
        ll m=l+(r-l)/2;
        if(check(m,cnt))
        {
            ans=m;
            l=m+1;
        }
        else
        {
            r=m-1;
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
    ll t; cin>>t;
    while(t--)
    {
        solve();
    }
}










