/*
    Author: HungForree
    Link: https://codeforces.com/problemset/problem/2169/D1
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
constexpr i64 inf = 1e12+1;

bool cal(ll x, ll y, ll m,ll k)
{
    if (y > 1) {

        double ratio = 1.0 - 1.0 / (double)y;
        double estimated = (double)m * pow(ratio, x);


        if (estimated >= k) return false;
    }
    for(ll i=1; i<= x;)
    {
        if(m<k) return true;
        if (m < y) return false;
        if (k > y && m - (x - i + 1) < k) return true;
        ll curr_val=m/y;
        if(curr_val==0) break;
        ll step= min((m%y)/curr_val+1,x-i+1);
        m-=step*curr_val;
        i+=step;

    }
    return m<k;
}
void solve()
{
    ll x,y,k; cin>>x>>y>>k;
    ll l=1, r=inf;
    ll ans=0;
    while(l<=r)
    {
        ll m=l+(r-l)/2;

        if(cal(x,y,m,k))
        {
            l=m+1;
            ans=m;
        }
        else
        {
            r=m-1;

        }
    }
    cout<<(ans>=inf-1?-1:ans+1)<<el;
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









