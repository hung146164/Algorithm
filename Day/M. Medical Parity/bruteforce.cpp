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
const ll N=1e6+5;
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
int sol(string& s, string& t,int curr=0,int v=0)
{
    if(curr==s.size()) return 0;
    int ans=INT_MAX;
    v+=s[curr]-'0';
    v%=2;
    //cout<<curr<<' '<<v<<' '<<t[curr]-'0'<<el;
    if(v==(t[curr]-'0'))
    {
        ans=min(ans,sol(s,t,curr+1,v));
    }
    else
    {
        ans=min(ans,1+sol(s,t,curr+1,v));
        ans=min(ans,1+sol(s,t,curr+1,(v+1)%2));
    }

    return ans;
}
void solve()
{
    string s,t; cin>>s>>t;
    cout<<sol(s,t)<<el;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int t; cin>>t;
    while(t--)
    {
        solve();
    }
}









