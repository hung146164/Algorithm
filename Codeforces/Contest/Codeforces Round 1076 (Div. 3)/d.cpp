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


void solve()
{
    ll n; cin>>n;
    vector<ll> a(n),b(n);
    ll total=n;
    for(ll i=0; i< n; i++)
    {
        cin>>a[i];
    }
    for(ll i=0; i< n; i++)
    {
        cin>>b[i];
    }

    vector<ll> prefixb;
    ll sum_b=0;
    for(ll i=0; i< b.size(); i++)
    {
        sum_b += b[i];
        prefixb.push_back(sum_b);
    }

    map<ll,ll> dp;
    for(ll i=0; i< n; i++)
    {
        dp[a[i]]++;
    }

    ll ans=0;
    for(auto& i: dp)
    {
        ll levels = upper_bound(prefixb.begin(), prefixb.end(), total) - prefixb.begin();
        ans = max(ans, levels * i.first);
        total -= i.second;
    }
    cout<<ans<<el;

}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin>>t;
    while(t--)
    {
        solve();
    }
}
