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

bool check(ll n, ll s, ll m)
{
    if (s / m >= n)
    {
        if(n* m < s) return false;
    }
    for (int k = 0;k < 60; k++)
    {
        ll mask = (1LL<<(k + 1))-1;
        ll have = s & mask;
        ll need = m & mask;
        //cout<<need<<' '<<have<<el;
        if (need==0)
        {
            if (have>0) return false;
        }
        else
        {
            ll limit= have/need;
            if (n<=limit) {

                if (n*need<have) return false;
            }
        }
    }
    return true;

}
void solve()
{
    ll s,m ; cin>>s>>m;
    if ((s & 1) && !(m&1)) {
        cout << -1 << el;
        return;
    }
    ll ans=-1;
    ll l = 1, r = 1e18;
    while (l <= r) {
        ll mid = l+(r-l)/2;
//        cout<<m<<' '<<el;
        if (check(mid, s, m)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << el;
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










