/*
    Author: HungForree
    Link:
*/

#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

#pragma GCC optimize("O3,unroll-loops")

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
template <typename A,typename B>
pair<A,B> operator +(const pair<A,B>& l, const pair<A,B>& r)
{
    return {l.first+r.first,l.second+r.second};
}
template <typename A,typename B>
pair<A,B> operator -(const pair<A,B>& l, const pair<A,B>& r)
{
    return {l.first-r.first,l.second-r.second};
}
pair<int,int> p[N];
void solve()
{
    int n,q; cin>>n>>q;
    map<char,pair<int,int>> mp;
    mp['L']={-1,0};
    mp['R']={1,0};
    mp['U']={0,1};
    mp['D']={0,-1};
    map<pair<int,int>,vector<int>> dp;
    dp[{0,0}].push_back(0);
    string s; cin>>s;
    int ca=0,cb=0;
    for(int i=0; i< n; i++)
    {
        pair<int,int> diff=mp[s[i]];
        ca+=diff.first;
        cb+=diff.second;
        p[i+1]={ca,cb};
        dp[{ca,cb}].push_back(i+1);
    }
    while(q--)
    {
        int x, y; cin>>x>>y;
        int l,r; cin>>l>>r;
        //out
        if(dp.find({x,y})!=dp.end())
        {
            vector<int>& curr=dp[{x,y}];
            if(curr[0]<=l-1 || curr[(int)curr.size()-1]>r)
            {
                cout<<"YES"<<el;
                continue;
            }
        }
        pair<int,int> curr=p[r]+p[l-1]-make_pair(x,y);
        if(dp.find(curr)!=dp.end())
        {
            vector<int>& ht=dp[curr];
            auto it=lower_bound(ht.begin(),ht.end(),l-1);
            if(it!=ht.end() && *it<r)
            {
                cout<<"YES"<<el;
                continue;
            }
        }
        cout<<"NO"<<el;
    }

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









