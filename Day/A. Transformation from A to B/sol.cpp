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
ll a, b;
void dfs(ll a,vector<int>& clone,vector<int>& ans,bool& have)
{
    if(have) return;
    if(a==b)
    {
        ans=clone;
        have=true;
    }
    if(a>b) return;
    clone.push_back(a*2);
    dfs(a*2,clone,ans,have);
    clone.pop_back();
    clone.push_back(a*10+1);
    dfs(a*10+1,clone,ans,have);
    clone.pop_back();
}
void solve()
{
    cin>>a>>b;
    vector<int> clone,ans;
    bool have=false;
    clone.push_back(a);
    dfs(a,clone,ans,have);
    if(ans.size()==0)
    {
        cout<<"NO"<<el;
        return;
    }
    cout<<"YES"<<el;
    cout<<ans.size()<<el;
    for(auto& i: ans)
    {
        cout<<i<<' ';
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









