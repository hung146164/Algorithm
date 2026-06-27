/*
    Author: HungForree
    Link: https://codeforces.com/group/py59YCge5m/contest/678451/problem/B
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

ll n;
void sol(ll pre,ll val,set<ll>& re)
{
    if(val>n) return ;
    if(pre<0 || pre>9) return ;
    re.insert(val);
    sol(pre-1,val*10+pre-1,re);
    sol(pre+1,val*10+pre+1,re);
}
void solve()
{
    cin>>n;

    cout<<0<<' ';
    set<ll> ans;
    for(ll i=1;i<=9; i++)
    {
        sol(i,i,ans);
    }
    for(ll i: ans) cout<<i<<' ';
    cout<<el;

}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}










