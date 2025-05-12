#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    map<ll,ll> dp;
    dp[0]=1;
    ll n, k; cin>>n>>k;
    vector<ll> nums;
    for(int i=0; i< n; i++)
    {
        ll x; cin>>x;
        nums.push_back(x);
    }
    ll sum=0;
    ll ans=0;
    for(int i=0; i< nums.size(); i++)
    {
        sum+=nums[i];
        ans+=dp[sum-k];


        dp[sum]++;
    }
    cout<<ans<<endl;
//    2 1
//    1 1
//    4 1

}
