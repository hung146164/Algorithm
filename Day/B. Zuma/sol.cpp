/*
    Author: HungForree
    Link: https://codeforces.com/problemset/problem/607/B
*/

#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
const ll N=505;
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
int nums[N];
int dp[N][N];
int sol(int l, int r)
{
    if(l==r)
    {
        return 1;
    }
    if(l>r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];
    int ans=INT_MAX;

    if(l==r-1)
    {
        return nums[l]==nums[r]?1:2;
    }
    for(int k=l+1;k<=r;k++)
    {
        if(nums[l]==nums[k])
        {
            ans=min(ans,(k-1<l+1?1:0)+sol(l+1,k-1)+sol(k+1,r));
        }
        else
        {
            ans=min(ans,sol(l,k-1)+sol(k,r));
        }
    }
    return dp[l][r]=ans;
}
void solve()
{
    memset(dp,-1,sizeof(dp));
    int n; cin>>n;
    for(int i=0; i< n; i++)
    {
        cin>>nums[i];
    }
    cout<<sol(0,n-1)<<el;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int t; t=1;
    while(t--)
    {
        solve();
    }
}










