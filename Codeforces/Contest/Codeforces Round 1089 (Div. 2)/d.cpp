/*
    Author: HungForree
    Link: https://codeforces.com/contest/2210/problem/D
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
ll nums[N];
ll getL(string& s)
{
    ll leaf = 0;
    for (ll i=0;i<s.length()-1;i++)
    {
        if (s[i]=='(' && s[i + 1]==')')
        {
            leaf++;
        }
    }
    return leaf;
}
ll getD(string& s)
{
    ll n = s.size();
    vector<ll> match(n);
    vector<ll> stackk;

    for (ll i = 0; i < n; i++)
    {
        if (s[i]=='(')
        {
            stackk.push_back(i);
        }
        else
        {
            ll open = stackk.back();
            stackk.pop_back();
            match[open] = i;
            match[i] = open;
        }
    }
    ll k=0;
    ll l=0,r=n-1;

    while(r-l>1&&match[l]==r)
    {
        k++;
        l++;
        r--;
    }
    return k;
}

void solve()
{
    ll n;
    cin>>n;
    string s,t;
    cin>>s>>t;

    if (getD(s)==getD(t)&&getL(s)==getL(t))
    {
        cout<<"YES"<<el;
    }
    else
    {
        cout<<"NO"<<el;
    }
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










