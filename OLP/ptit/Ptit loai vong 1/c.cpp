#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin>>n;
    vector<ll> nums;
    ll sum=0;
    for(int i=0; i< n; i++)
    {
        ll x ;cin>>x;
        nums.push_back(x);
        sum+=x;
    }
    sort(nums.begin(),nums.end());
    ll ans=0;
    for(int i=n-1; i>=1; i--)
    {
        sum-=nums[i];
        ans+=i*nums[i]-sum;
    }
    cout<<ans<<'\n';

}
