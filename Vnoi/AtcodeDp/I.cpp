/*
    Author: HungForree
    Link: https://oj.vnoi.info/problem/atcoder_dp_i
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
void solve()
{
    int n; cin>>n;
    vector<double> nums(n);
    for(int i=0; i< n; i++)
    {
        cin>>nums[i];
    }
//    for(int i=0; i< n; i++)
//    {
//        cout<<nums[i]<<' ';
//    }
//    cout<<el;
    int need=(n-1)/2;
    // gọi dp[i][j] là xác xuất khi xét đến phần tử thứ i thì đã có j mặt up
    // dp[i][j]= dp[i-1][j]* xs(ngua) + dp[i-1][j-1]*xs(up);
    vector<vector<double>> dp(n+1,vector<double>(need+1));
    dp[0][0]=1;
    for(int i=1; i<= n; i++)
    {
        dp[i][0]=dp[i-1][0]*nums[i-1];
    }
    for(int j=1;j<=need; j++)
    {
        dp[0][j]=0;
    }
    for(int i=1; i<= n;i++)
    {
        for(int j=1;j<=need; j++)
        {
            dp[i][j]=dp[i-1][j]*nums[i-1]+dp[i-1][j-1]*(1-nums[i-1]);
        }
    }
//    for(int i=0; i<=n; i++)
//    {
//        for(int j=0; j<=need; j++)
//        {
//            cout<<dp[i][j]<<' ';
//        }
//        cout<<el;
//    }
    double ans=0;
    for(int j=0;j<=need;j++)
    {
        ans+=dp[n][j];
    }
    cout<<fixed<<setprecision(9)<<ans<<el;

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





