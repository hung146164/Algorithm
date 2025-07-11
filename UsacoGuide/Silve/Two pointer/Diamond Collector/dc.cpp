#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    freopen("diamond.in","r",stdin);
   freopen("diamond.out","w",stdout);
    ll n,k; cin>>n>>k;
    vector<ll> dp;
    for(ll i=0; i<n; i++)
    {
        ll x; cin>>x;
        dp.push_back(x);
    }
    sort(dp.begin(),dp.end());
    vector<ll> left(n),right(n);

    ll l,r;
    for(l=0,r=0; r<n; r++)
    {
        while(dp[r]-dp[l]>k)
        {
            l++;
        }
        left[r]=r-l+1;
    }
    for(l=n-1,r=n-1; r>=0; r--)
    {
        while(dp[l]-dp[r]>k)
        {
            l--;
        }
        right[r]=l-r+1;
    }
    ll ans=0;
    for(ll i=1; i<left.size(); i++)
    {
        left[i]=max(left[i-1],left[i]);
    }
    for(ll i=n-2; i>=0; i--)
    {
        right[i]=max(right[i],right[i+1]);
    }
//    for(int i=0; i< dp.size(); i++)
//    {
//        cout<<dp[i]<<" ";
//    }
//    cout<<endl;
//        for(int i=0; i< left.size(); i++)
//    {
//        cout<<left[i]<<" ";
//    }
//    cout<<endl;
//    for(int i=0; i< right.size(); i++)
//    {
//        cout<<right[i]<<" ";
//    }
//    cout<<endl;

    ans=max(ans,max(right[0],left[n-1]));
    for(ll i=0; i< n-1; i++)
    {
        ans=max(ans,left[i]+right[i+1]);
    }
    cout<<ans<<endl;
}
