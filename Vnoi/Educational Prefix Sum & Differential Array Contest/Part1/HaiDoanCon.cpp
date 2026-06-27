#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n; cin>>n;
    vector<ll> pl(n),pr(n);
    vector<ll> nums;
    for(ll i=0; i< n; i++)
    {
        ll x; cin>>x;
        nums.push_back(x);
    }

    ll pre=pl[0]=nums[0];
    for(ll i=1; i<n;i++)
    {
        pre=max(nums[i],pre+nums[i]);
        pl[i]=max(pre,pl[i-1]);
    }

    pre=pr[n-1]=nums[n-1];
    for(ll i=n-2;i>=0; i--)
    {
        pre=max(nums[i],pre+nums[i]);
        pr[i]=max(pre,pr[i+1]);
    }
    ll ans=INT_MIN;
    for(ll i=0; i<n-1;i++)
    {
        ans=max(ans,pl[i]+pr[i+1]);
    }
//    for(ll i=0; i< pl.size(); i++)
//    {
//        cout<<pl[i]<<' ';
//    }
//    cout<<'\n';
//    for(ll i=0; i< pr.size(); i++)
//    {
//        cout<<pr[i]<<' ';
//    }
//    cout<<'\n';
    cout<<ans<<'\n';
}
