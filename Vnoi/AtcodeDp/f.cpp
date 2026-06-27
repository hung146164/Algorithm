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
int dp[3005][3005];
void sol()
{
    string s, t; cin>>s>>t;
    int n=s.size(),m=t.size();

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(s[i-1]==t[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j]);
                dp[i][j]=max(dp[i][j-1],dp[i][j]);
            }
        }
    }
//    for(int i=0; i<=n; i++)
//    {
//        for(int j=0; j<=m; j++)
//        {
//            cout<<dp[i][j]<<' ';
//        }
//        cout<<el;
//    }
    string ans;
    int start=n,end=m;
    while(start!=0 && end!=0)
    {
        if(s[start-1]==t[end-1])
        {
            ans.push_back(s[start-1]);
            end--;
            start--;
        }
        else
        {
            if(dp[start-1][end]>dp[start][end-1])
            {
                start--;
            }
            else{
                end--;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<el;
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
        sol();
    }
}




