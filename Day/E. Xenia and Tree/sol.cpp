/*
    Author: HungForree
    Link: https://codeforces.com/problemset/problem/342/E
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
const ll loga=18;

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
int cnt[N];
int depth[N];

int parent[loga+1][N];
vector<int> g_con[N];
int n,q;
vector<int> red;
void build(int curr ,int p=0,int d=1)
{
    parent[0][curr]=p;
    depth[curr]=d;
    for(auto& v: g_con[curr])
    {
        if(v==p) continue;
        build(v,curr,d+1);
    }
}
int lca(int a, int b)
{
    if(depth[a]>depth[b])
    {
        swap(a,b);
    }
  //  cout<<"F "<<a<<' '<<b<<el;
    for(int i=loga;i>=0 ;i--)
    {
        if((depth[parent[i][b]]) >= depth[a])
        {
            b=parent[i][b];
        }
    }
    //cout<<b<<' '<<a<<el;
    if(b==a) return a;
    for(int i=loga;i>=0; i--)
    {
        if(parent[i][a] != parent[i][b])
        {
            a=parent[i][a];
            b=parent[i][b];
        }
    }
    return parent[0][a];
}
int query(int x)
{
    //cout<<x<<": ";
    int ans=INT_MAX;
    for(auto& node: red)
    {
        //cout<<cnt[x]<<' '<<depth[x]+depth[node]-2*depth[lca(x,node)]<<' '<<x<<' '<<node<<el;
        ans=min(ans,depth[x]+depth[node]-2*depth[lca(x,node)]);
    }
    return ans;
}
void update()
{
    queue<int> q;
    for(int i=0; i< red.size() ;i++)
    {
        cnt[red[i]]=0;
        q.push(red[i]);
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for (int v : g_con[u])
        {
            if (cnt[v] > cnt[u] + 1)
            {
                cnt[v] = cnt[u] + 1;
                q.push(v);
            }
        }
    }
    red.clear();
}
void solve()
{
     cin>>n>>q;
    for(int i=1;i<=n; i++)
    {
        cnt[i]=INT_MAX;
    }

    for(int i=0; i<n-1 ;i++)
    {
        int a, b; cin>>a>>b;
        g_con[a].push_back(b);
        g_con[b].push_back(a);
    }
    build(1);
    red.push_back(1);

    for(int j=1; j<=loga ;j++)
    {
        for(int i=1; i<= n; i++)
        {
            parent[j][i]=parent[j-1][parent[j-1][i]];
        }
    }

    int k=76;
    //cout<<"LCA "<<lca(1,5)<<el;
    //cout<<depth[0]<<' '<<depth[1]<<el;
    for(int i=1; i<= q; i++)
    {
        int a, b; cin>>a>>b;
        if(a==1)
        {
            red.push_back(b);
        }
        else{

            cout<<min(cnt[b],query(b))<<el;
        }
//        for(int i=1;i<=n; i++) cout<<cnt[i]<<' ';
//        cout<<el;
        if((int)red.size()>=k)
        {
            update();
        }
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









