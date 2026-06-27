/*
    Author: HungForree
    Link: https://codeforces.com/problemset/problem/1398/D
*/

#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
const ll N=205;
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
int dp[N][N][N];
int sol(vector<int>& a, vector<int>& b, vector<int>& c, int x=0,int y=0,int z=0)
{
    int cnt=0;
    if(x==a.size()) cnt++;
    if(y==b.size()) cnt++;
    if(z==c.size()) cnt++;
    if(cnt>1) return 0;
    if(dp[x][y][z]!=-1) return dp[x][y][z];
    int ans=0;
    if(x<a.size() && y<b.size())
    {
        ans=max(ans,a[x]*b[y]+sol(a,b,c,x+1,y+1,z));
    }
    if(x<a.size() && z<c.size())
    {
        ans=max(ans,a[x]*c[z]+sol(a,b,c,x+1,y,z+1));
    }
    if(z<c.size() && y<b.size())
    {
        ans=max(ans,c[z]*b[y]+sol(a,b,c,x,y+1,z+1));
    }
    return dp[x][y][z]=ans;
}
void solve()
{
    int r,g,bb; cin>>r>>g>>bb;

    vector<int> a,b,c;
    for(int i=0;i<r; i++)
    {
        int x; cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<g; i++)
    {
        int x; cin>>x;
        b.push_back(x);
    }
    for(int i=0;i<bb; i++)
    {
        int x; cin>>x;
        c.push_back(x);
    }
    sort(a.begin(),a.end(),greater<int>());
    sort(b.begin(),b.end(),greater<int>());
    sort(c.begin(),c.end(),greater<int>());
    cout<<sol(a,b,c)<<el;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int t; t=1;
    memset(dp,-1,sizeof(dp));
    while(t--)
    {
        solve();
    }
}









