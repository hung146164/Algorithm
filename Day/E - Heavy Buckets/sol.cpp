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

ll child[31][N];
ll val[31][N];
void solve()
{
    ll n,q ;cin>>n>>q;
    vector<ll> nums(n+1);
    for(ll i=1; i<= n; i++)
    {
        cin>>nums[i];
    }
    for(ll i=1; i<=n; i++)
    {
        child[0][i]=nums[i];
    }
    for(ll j=1;j<31; j++)
    {
        for(ll i=1;i<=n; i++)
        {
            child[j][i]=child[j-1][child[j-1][i]];
        }
    }
    for(ll i=1;i<=n; i++)
    {
        val[0][i]=i;
    }
    for(ll j=1; j<31; j++)
    {
        for(ll i=1;i<=n; i++)
        {
            val[j][i]=val[j-1][child[j-1][i]]+val[j-1][i];
        }
    }
//    for(ll j=0;j<=5; j++)
//    {
//        for(ll i=1;i<=n; i++)
//        {
//            cout<<val[j][i]<<' ';
//        }
//        cout<<el;
//    }
    while(q--)
    {
        ll a, b; cin>>b>>a;
        ll ans=0;
        for(ll i=30; i>=0 ;i--)
        {
            if(b>=(1<<i))
            {
                ans+=val[i][a];
                a=child[i][a];
                b-=(1<<i);
            }
        }
        cout<<ans<<el;
    }

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









