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
int nums[N];
vector<int> g[N];
int child_count[N];
int max_child[N];
void dfs(int curr ,int p=0)
{
    child_count[curr]=1;
    for(auto& v: g[curr])
    {
        if(v==p) continue;
        dfs(v,curr);
        child_count[curr]+=child_count[v];
        max_child[curr]=max(max_child[curr],child_count[v]);
    }
}
void solve()
{
    int n; cin>>n;
    for(int i=0; i< n-1; i++)
    {
        int a, b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    int ans=1;
    for(int i=1;i<=n; i++)
    {
        max_child[i]=max(child_count[1]-child_count[i],max_child[i]);
        if(max_child[i]<=n/2)
        {
            ans=i;
        }
    }

    cout<<ans<<el;
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










