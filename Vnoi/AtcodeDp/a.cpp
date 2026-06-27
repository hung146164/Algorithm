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
int nums[N],dp[N];
void sol()
{
    int n; cin>>n;int k; cin>>k;
   for(int i=0; i<n; i++)
   {
       cin>>nums[i];
   }
   for(int i=0; i< n; i++)
   {
       dp[i]=INT_MAX;
   }
   dp[0]=0;
   for(int i=1; i<n; i++)
   {
        for(int j=i-1;j>=i-k && j>=0 ; j--)
       {
           dp[i]=min(dp[i],abs(nums[i]-nums[j])+dp[j]);
       }
   }
//   for(int i=0; i< n; i++) cout<<dp[i]<<' ';
//   cout<<el;
   cout<<dp[n-1]<<el;
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





