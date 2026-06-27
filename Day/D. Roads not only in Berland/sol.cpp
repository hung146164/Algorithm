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
const ll N=1005;
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
int p[N];
int du[N];

int find(int u)
{
    if(u==p[u])
    {
        return u;
    }
    return p[u]=find(p[u]);
}
bool join(int a, int b)
{
    int pa=find(a);
    int pb=find(b);
    if(pa==pb) return false;
    p[pb]=pa;
    return true;
}
void process(int n)
{
    for(int i=1; i<=n; i++)
    {
        p[i]=i;
    }
}

void solve()
{
    int n; cin>>n;
    process(n);
    vector<vector<int>> thua;
    set<int> root;
    for(int i=0; i< n-1; i++)
    {
        int a, b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
        int pa=find(a);
        if(!join(a,b))
        {
            thua.push_back({a,b});
        }
    }
    for(int i=1;i <=n; i++)
    {
        root.insert(find(i));
    }
    vector<int> haha;
    for(auto & v: root) haha.push_back(v);
    cout<<thua.size()<<el;
    for(int i=1; i<haha.size(); i++)
    {
        cout<<thua[i-1][0]<<' '<<thua[i-1][1]<<' '<<haha[0]<<' '<<haha[i]<<el;
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










