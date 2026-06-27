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
const ll N=305;
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
vector<int> g[N];
vector<int> road[N];
vector<int> r_road[N];
vector<int> leaf;
void dfs(int curr ,vector<int>& clone,int p=0)
{
    clone.push_back(curr);
    bool isleaf=true;
    for(auto& v: g[curr])
    {
        if(v==p) continue;
        isleaf=false;
        dfs(v,clone,curr);
    }
    if(isleaf)
    {
        road[curr]=clone;
        leaf.push_back(curr);
    }
    clone.pop_back();
}
void dfs2(int a, int b, vector<int>& ht,vector<int>& clone,int p=0)
{
    clone.push_back(a);
    if(a==b)
    {
        ht=clone;
        return;
    }

    for(auto& v: g[a])
    {
        if(v==p) continue;
        dfs2(v,b,ht,clone,a);
    }
    clone.pop_back();
}
void solve()
{
    int n; cin>>n;
    for(int i=0; i< n-1; i++)
    {
        int a, b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> clone;
    dfs(1,clone);
    for(int i=1; i<=n;i++)
    {
        vector<int> clone = road[i];
        reverse(clone.begin(),clone.end());
        r_road[i]=clone;
        //cout<<clone.size()<<' '<<r_road[i].size()<<endl;
    }
    for(int i=0; i< leaf.size(); i++)
    {
        cin>>leaf[i];
    }
//    for(int i=0; i< 5; i++)
//    {
//        cout<<r_road[i].size()<<endl;
//        for(auto j: r_road[i])
//        {
//            cout<<j<<' ';
//        }
//        cout<<endl;
//    }

    map<pair<int,int>,int> dp;
    vector<int> ans;
    ans.push_back(1);
    vector<int> curr=road[leaf[0]];
    for(int i=1; i<curr.size(); i++)
    {
        dp[{curr[i-1],curr[i]}]++;
        ans.push_back(curr[i]);
    }

    for(int i=1; i<leaf.size(); i++)
    {
        vector<int> ht;
        vector<int> clone;
        dfs2(leaf[i-1],leaf[i],ht,clone);
        for(int j=1;j<ht.size(); j++)
        {
            dp[{ht[j-1],ht[j]}]++;
            dp[{ht[j],ht[j-1]}]++;
            ans.push_back(ht[j]);
        }
    }
    vector<int> ht=r_road[leaf[leaf.size()-1]];
    for(int j=1;j<ht.size(); j++)
        {
            dp[{ht[j-1],ht[j]}]++;
            dp[{ht[j],ht[j-1]}]++;
            ans.push_back(ht[j]);
        }
       // cout<<"HAHA"<<el;
    for(auto i : dp)
    {
        //cout<<i.first.first<<' '<<i.first.second<<' '<<i.second<<el;
        if(i.second>2)
        {
            cout<<-1<<el;
            return;
        }
    }
    for(int i=0; i< ans.size(); i++)
    {
        cout<<ans[i]<<' ';
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








