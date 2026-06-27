#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=1e5+1;

ll dp[1001][1001];

//sub1
void sub1(ll n,ll t,ll a,ll b,vector<ll>& nums)
{

    ll ans=0;
    for(ll i=0; i< n; i++)
    {
        if(t>=a)
        {
            ans+=nums[i];
            t-=a;
        }
    }
    cout<<ans<<'\n';
}


//sub2

ll bt(vector<ll>& nums, ll curr, ll t, ll a, ll b)
{
    if(curr==nums.size() || t<0) return 0;
    if(dp[curr][t]!=-1) return dp[curr][t];
    ll ans=0;
    //an
    if(t>=a) ans=max(ans,nums[curr]+bt(nums,curr+1,t-a,a,b));
    //bo
    if(t>=b) ans=max(ans,bt(nums,curr+1,t-b,a,b));

    return dp[curr][t]=ans;
}
void sub2(ll n,ll t,ll a,ll b,vector<ll>& nums)
{
    memset(dp,-1,sizeof(dp));
    ll ans=0;
    cout<<bt(nums,0,t,a,b)<<'\n';
}
//sub3

void sub3(ll n,ll t,ll a,ll b,vector<ll>& nums)
{

    vector<ll> prefixbo(n+1),prefixan(n+1),prefixsum(n+1);
    ll ans=0;
    for(ll i=0; i< nums.size(); i++)
    {
        prefixbo[i+1]=prefixbo[i]+b;
        prefixan[i+1]=prefixan[i]+a;
        prefixsum[i+1]=prefixsum[i]+nums[i];
    }
    for(ll i=0; i<=n; i++)
    {
        ans=max(ans,prefixsum[prev(upper_bound(prefixan.begin(),prefixan.end(),t-prefixbo[i]+prefixan[i]))-prefixan.begin()]-prefixsum[i]);
    }
    cout<<ans<<'\n';
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,t,a,b;cin>>n>>t>>a>>b;
    vector<ll> nums;
    for(ll i=0; i< n; i++)
    {
        ll x; cin>>x;
        nums.push_back(x);
    }
    if(n<=1000 && t<=1000)
    {
        sub2(n,t,a,b,nums);
        return 0;
    }
    bool is3=true;
    for(ll i=1; i<n; i++)
    {
        if(nums[i-1]>=nums[i]) is3=false;
    }
    if(is3)
    {
        sub3(n,t,a,b,nums);
    }
    else
    {
        sub1(n,t,a,b,nums);
    }
}


