#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("pairup.in","r",stdin);
    freopen("pairup.out","w",stdout);

    int n;cin>>n;
    vector<pair<int,int>> dp;
    for(int i=0; i< n; i++)
    {
        int a,b; cin>>a>>b;

        dp.push_back({b,a});
    }
    sort(dp.begin(),dp.end());

    int l=0,r=n-1;
    int ans=0;
    while(l<=r)
    {


        int c=min(dp[l].second,dp[r].second);

        ans=max(ans,dp[l].first+dp[r].first);

        dp[l].second-=c;
        dp[r].second-=c;
        if(dp[l].second==0) l++;
        if(dp[r].second==0) r--;
        if(l==r) break;


    }
    cout<<ans<<endl;

}
