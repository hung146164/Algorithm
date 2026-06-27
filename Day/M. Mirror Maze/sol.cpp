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
vector<int> dp[201][201][4];
int cache[201][201][4];
char g[201][201];
bool check[201][201];
int id=1;
int n,m;
int mir=0;
//cnt dir
set<pair<int,int>> ans;
int dx[]{0,0,1,-1};
int dy[]{-1,1,0,0};
char h[]{'W','E','S','N'};
vector<int> sol(int x,int y,int dir,int cnt=0)
{
    //cout<<x<<' '<<y<<' '<<dir<<' '<<cnt<<el;
    if(x<0  || x>=n )
    {
        if(cnt==mir)
        {
            ans.insert({dir,y});
        }
        return {cnt,dir,y};
    }
    if(y>=m || y<0)
    {
        if(cnt==mir)
        {
            ans.insert({dir,x});
        }
        return {cnt,dir,x};
    }
    if(cache[x][y][dir]==id)
    {
        if(dp[x][y][dir][0]+cnt == mir)
        {
            ans.insert({dp[x][y][dir][1],dp[x][y][dir][2]});
        }
        return dp[x][y][dir];
    }
    int extra=0;
    // left right down up
    if(g[x][y]!='.')
    {
        if(g[x][y]=='/')
        {
            if(dir==0) dir=2;
            else if(dir==1) dir=3;
            else if(dir==2) dir=0;
            else dir=1;
        }
        else{
            if(dir==0) dir=3;
            else if(dir==1) dir=2;
            else if(dir==2) dir=1;
            else dir=0;
        }
        if(!check[x][y]) extra=1;
    }
    check[x][y]=true;
    vector<int> hehe= sol(x+dx[dir],y+dy[dir],dir,cnt+extra);
    check[x][y]=false;
    return hehe;

}
void solve()
{

    cin>>n>>m;
    for(int i=0; i< n; i++)
    {
        for(int j=0; j<m ;j++)
        {
            cin>>g[i][j];
            if(g[i][j]!='.') mir++;
        }
    }
    //cout<<mir<<el;
    //cout<<ans.size()<<el;
    for(int j=0; j< m; j++)
    {
        //cout<<el;
        sol(0,j,2);
       // cout<<el;
        sol(n-1,j,3);
        //cout<<el;
    }
    for(int i=0; i<n ;i++)
    {
        //cout<<el;
        sol(i,0,1);
        //cout<<el;
        sol(i,m-1,0);
        //cout<<el;
    }
    cout<<ans.size()<<el;
    for(auto& i: ans)
    {
        cout<<h[i.first];
        cout<<i.second+1<<' ';
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









