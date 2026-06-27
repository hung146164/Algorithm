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
ll pow2[61];
void process()
{
    pow2[0]=1;
    for(int i=1; i<61; i++)
    {
        pow2[i]=pow2[i-1]*2;
    }
}
map<ll,ll> dp;
ll f = inf;
void sol(ll x, ll y, ll cnt)
{
    if(y <= x)
    {
       /// cout << x - y + cnt <<" " << x <<" "<<y<<el;
       f = min(f,x-y+cnt);
        return ;
    }
   if(y < 2*x)
   {
       if(y % 2 == 0) f = min(f, cnt + min(y-x,x- y/2 + 1));
       else f = min(f, cnt + min(y-x,x- (y+1)/2 + 2));
       return;
   }
   if(y % 2 == 0)
   {
       sol(x,y/2,cnt+1);
   }
   else
   {
       sol(x,(y-1),cnt+1);
       sol(x,(y+1),cnt+1);
   }
}
void solve()
{
    ll x,y; cin>>x>>y;
    if(x>=y)
    {
        cout<<x-y<<el;
        return;
    }
    sol(x,y,0);
    cout << f;
//    cout<<bitset<8>(x)<<el;
//    cout<<bitset<8>(y)<<el;
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









