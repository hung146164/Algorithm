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
int dp[1000][1000];
int sol(int l,int r, vector<int>& nums)
{
    if(l==r) return nums[l];
    if(dp[l][r]!=-1)
    {
        return dp[l][r];
    }
    int ans=0;
    ans=max(ans,nums[l]-sol(l+1,r,nums));
    ans=max(ans,nums[r]-sol(l,r-1,nums));
    return dp[l][r]=ans;
}
void solve()
{
    int n; cin>>n;
    vector<int> nums(n);
    for(int i=0; i< n; i++)
    {
        cin>>nums[i];
    }
    int l=0,r=n-1;
    int a=0,b=0;
    int f=0;
    while(l<=r)
    {
        if(nums[l]>nums[r])
        {
            if(f%2==0)
            {
                a+=nums[l];
            }
            else
            {
                b+=nums[l];
            }
            l++;
        }
        else
        {

            if(f%2==0)
            {
                a+=nums[r];
            }
            else
            {
                b+=nums[r];
            }
            r--;
        }
        f++;
    }
    cout<<a<<' '<<b<<'\n';
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






