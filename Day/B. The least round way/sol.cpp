/*
    Author: HungForree
    Link: https://codeforces.com/contest/2/problem/B
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

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

ll dp2[N][N];
ll dp5[N][N];
int trace2[N][N];
int trace5[N][N];
pair<ll,ll> nums[N][N];
void solve()
{
    ll n;
    cin>>n;
    bool havezero=false;
    int zx=0,zy=0;
    for(ll i=1; i<=n; i++)
    {
        for(ll j=1; j<=n; j++)
        {
            ll x;
            cin>>x;
            if(x==0)
            {
                havezero=true;
                zx=i;
                zy=j;
                continue;
            }
            pair<ll,ll> curr{0,0};
            while(x%5==0)
            {
                curr.second++;
                x/=5;
            }
            while(x%2==0)
            {
                curr.first++;
                x/=2;
            }
            nums[i][j]=curr;
        }
    }
    dp2[0][1]=0;
    dp5[0][1]=0;
    for(ll i=1; i<=n; i++)
    {
        for(ll j=1; j<=n; j++)
        {
            dp2[i][j]=min(dp2[i-1][j],dp2[i][j-1])+nums[i][j].first;
            if(dp2[i-1][j]>dp2[i][j-1])
            {
                trace2[i][j]=1;
            }
            dp5[i][j]=min(dp5[i-1][j],dp5[i][j-1])+nums[i][j].second;
            if(dp5[i-1][j]>dp5[i][j-1])
            {
                trace5[i][j]=1;
            }
        }
    }
    if(min(dp2[n][n],dp5[n][n])>0 && havezero)
    {
        cout<<1<<el;
        for(int ii=2; ii<=zx; ii++)
        {
            cout<<'D';
        }
        for(int ii=2; ii<=zy ; ii++)
        {
            cout<<'R';
        }
        for(int ii=zx+1; ii<=n; ii++)
        {
            cout<<'D';
        }
        for(int ii=zy+1; ii<=n; ii++)
        {
            cout<<'R';
        }
        return;
    }
    cout<<min(dp2[n][n],dp5[n][n])<<el;
    vector<char> ans;
    int x=n,y=n;
    if(dp2[n][n]<dp5[n][n])
    {
        while(!(x==1&&y==1))
        {
            if(trace2[x][y]==1)
            {
                y--;
                ans.push_back('R');
            }
            else
            {
                x--;
                ans.push_back('D');
            }
        }
    }
    else
    {
        while(!(x==1&&y==1))
        {
            if(trace5[x][y]==1)
            {
                y--;
                ans.push_back('R');
            }
            else
            {
                x--;
                ans.push_back('D');
            }
        }
    }
    for(int i=ans.size()-1; i>=0; i--) cout<<ans[i];
    cout<<el;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    for(ll i=0; i<N; i++)
    {
        for(ll j=0; j<N; j++)
        {
            dp2[i][j]=dp5[i][j]=inf;
        }
    }
    ll t;
    t=1;
    while(t--)
    {
        solve();
    }
}










