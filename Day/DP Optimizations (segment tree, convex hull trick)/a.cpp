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
int nums[N],prefix[N];
int dp[N];
int tree[N*4];
void update(int curr ,int l, int r,int x,int val)
{
    if(l==r)
    {
        tree[curr]=val;
        return;
    }
    int m=l+(r-l)/2;
    if(x<=m) update(curr<<1,l,m,x,val);
    else update(curr<<1|1,m+1,r,x,val);
    tree[curr]=min(tree[curr<<1],tree[curr<<1|1]);
}
int query(int curr ,int l, int r, int x, int y)
{
    if(x<=l && r<=y)
    {
        return tree[curr];
    }
    if(r<x || l>y) return INT_MAX;
    int m=l+(r-l)/2;
    return min(query(curr<<1,l,m,x,y),query(curr<<1|1,m+1,r,x,y));
}
void solve()
{
    for(int i=0; i< 4*N; i++)
    {
        tree[i]=INT_MAX;
    }
    int n; cin>>n;
    for(int i=1;i<=n; i++)
    {
        cin>>nums[i];
        prefix[i]=nums[i]+prefix[i-1];
    }
    dp[0]=0;
    dp[1]=0;
    update(1,1,n,1,0);
    //vector<int> ans(n);

    for(int i=2; i<=n; i++)
    {
        int a, b; cin>>a>>b;
        dp[i]=prefix[i]+query(1,1,n,a,b);
        update(1,1,n,i,dp[i]-prefix[i-1]);
    }
    for(int i=1;i<=n; i++)
    {
        cout<<dp[i]<<' ';
    }
    cout<<el;

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









