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

void sol()
{
    int n; cin>>n;
    vector<vector<int>> nums(n,vector<int>(3));
    for(int i=0; i< n; i++)
    {
        for(int j=0; j< 3; j++)
        {
            cin>>nums[i][j];
        }
    }
    vector<int> dp(3);
    for(int i=0; i< 3; i++)
    {
        dp[i]=nums[0][i];
    }
    for(int i=1; i< n; i++)
    {
        vector<int> nn(3,0);
        for(int j=0; j< 3; j++)
        {
            for(int k=0; k< 3; k++)
            {
                if(j!=k)
                {
                    nn[j]=max(nn[j],dp[k]+nums[i][j]);
                }
            }
        }
//        for(int j=0; j< nn.size(); j++)
//        {
//            cout<<nn[i]<<' ';
//        }
//        cout<<el;
        dp=nn;
    }
    int ans=0;
    for(int i=0;i< 3; i++)
    {
        ans=max(ans,dp[i]);
    }
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





