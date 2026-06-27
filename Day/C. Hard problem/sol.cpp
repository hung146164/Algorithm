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
string s[N];
int C[N];
bool cmp[N][2][2];
ll dp[N][2];
int n;
bool ss(string& a, string& b)
{
    int n=a.size(),m=b.size();
    int e=min(n,m);
    for(int i=0; i< e; i++)
    {
        if(a[i]<b[i]) return true;
        else if(a[i]>b[i]) return false;
    }
    return n<=m;
}
ll sol(ll curr=1,ll pre=0)
{
    if(curr>n) return 0;
    if(dp[curr][pre]!=-1) return dp[curr][pre];
    ll ans=inf;
    if(cmp[curr][pre][0]) ans=min(ans,sol(curr+1,0));
    if(cmp[curr][pre][1]) ans=min(ans,C[curr]+sol(curr+1,1));
    return dp[curr][pre]=ans;
}
void solve()
{
    cin>>n;
    for(ll i=1; i<=n; i++)
    {
        cin>>C[i];
    }
    cmp[1][0][0]=cmp[1][0][1]=cmp[1][1][0]=cmp[1][1][1]=true;
    for(ll i=1; i<=n; i++)
    {
        cin>>s[i];
    }
    for(ll i=2; i<=n; i++)
    {
        string a=s[i-1];
        string b=s[i];
        cmp[i][0][0]=ss(a,b);
        reverse(b.begin(),b.end());
        cmp[i][0][1]=ss(a,b);
        reverse(a.begin(),a.end());
        cmp[i][1][1]=ss(a,b);
        reverse(b.begin(),b.end());
        cmp[i][1][0]=ss(a,b);
    }
//    for(ll i=1; i<=n; i++)
//    {
//        for(ll j=0; j<2; j++)
//        {
//            for(ll k=0; k<2; k++)
//            {
//                cout<<cmp[i][j][k]<<' ';
//            }
//            cout<<el;
//        }
//        cout<<el;
//    }
    ll ans=sol();
    cout<<(ans>=inf?-1:ans)<<el;

}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    memset(dp,-1,sizeof(dp));
    ll t;
    t=1;
    while(t--)
    {
        solve();
    }
}










