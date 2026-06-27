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
const ll inf=1e18;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll base=rng() % 500 +300;
ll powll(ll a, ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a%mod;
        }
        a=a*a%mod;
        b/=2;
    }
    return ans;
}
bool can[N][3];
void sol(vector<vector<int>>& g, int curr,int p=-1)
{
    if(g[curr].size()==1 && g[curr][0]==p)
    {
        can[curr][1]=true;
        return;
    }
    for(int i=0; i< g[curr].size(); i++)
    {
        if(g[curr][i]==p) continue;
        sol(g,g[curr][i],curr);
    }
    set<int> s;
    for(int i=0; i< g[curr].size(); i++)
    {
        if(g[curr][i]==p) continue;
        set<int> clone;
        for(int j=0; j< 3; j++)
        {
            if(can[g[curr][i]][j])
            {
                clone.insert(j);
            }
        }
        if(s.size()==0)
        {
            s=clone;
        }
        else
        {
            set<int> c2;
            for(auto& v1: clone)
            {
                for(auto& v2:s)
                {
                    c2.insert((v1+v2)%3);
                }
            }
            s=c2;
        }
    }
    for(auto& i: s)
    {
        can[curr][i]=true;
    }
    can[curr][1]=true;
}
void solve()
{
    memset(can,false,sizeof(can));
    int n; cin>>n;
    vector<vector<int>> g(n+1);
    for(int i=0; i< n-1; i++)
    {
        int a, b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    sol(g,1);

    // goi dp[i][j] la có tồn tại [(số lượng đỉnh) %3 ] có thể xóa bên dưới cây con gốc i
    // gọi k là đỉnh đang xét hiện tại nếu k là lá thì dp[k][1]=true
    // gọi k là đỉnh đang xét nếu k không phải là lá , dp[k][1]=true;

    cout<<(can[1][0]==true?"YES":"NO")<<el;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t; cin>>t;
    while(t--)
    {
        solve();
    }
}







