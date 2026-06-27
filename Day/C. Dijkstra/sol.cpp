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
const ll N=1e5+5;
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
vector<pair<int,int>> g[N];
int trace[N];
void solve()
{
    memset(trace,-1,sizeof(trace));
    int n,m ; cin>>n>>m;
    for(int i=0; i<m ;i++)
    {
        int a, b, c; cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    vector<bool> check(n+1);
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    pq.push({0,1,-1});
    while(!pq.empty())
    {
        vector<int> curr=pq.top();
        pq.pop();
        int val=curr[0];
        int node=curr[1];
        int pre=curr[2];
        if(check[node]) continue;
        check[node]=true;
        trace[node]=pre;
        if(node==n) break;
        for(auto&[v,w]: g[node])
        {
            if(!check[v])
            {
                pq.push({w+val,v,node});

            }
        }
    }
    if(!check[n])
    {
        cout<<-1;
        return;
    }
    vector<int> ans;
    int curr=n;
    while(curr!=-1)
    {
        //cout<<curr<<el;
        ans.push_back(curr);
        curr=trace[curr];
    }
    for(int i=(int)ans.size()-1; i>=0; i--) cout<<ans[i]<<' ';

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









