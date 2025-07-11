#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,s ; cin>>n>>s;
    ll sum=0;
    ll l=0;
    ll ans=0;
    vector<ll> nums;
    for(ll i=0; i<n; i++)
    {
        ll x ;cin>>x;
        nums.push_back(x);
    }
    for(ll r=0; r< n; r++)
    {
        sum+=nums[r];
        while(sum>=s)
        {
            sum-=nums[l];
            l++;
        }
        ans+=l;
    }
    cout<<ans<<endl;
}
