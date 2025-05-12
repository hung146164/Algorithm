#include<bits/stdc++.h>
using namespace std;
vector<int> sol(vector<int>& nums,int x)
{
    int n= nums.size();
    vector<pair<int,int>> dp;
    for(int i=0; i< nums.size(); i++)
    {
        dp.push_back({nums[i],i});
    }
    sort(dp.begin(), dp.end());
    for(int i=0; i< n-2; i++)
    {
        int l=i+1; int r=n-1;
        int sum=x-dp[i].first;
        while(l<r)
        {
            if(dp[l].first+dp[r].first==sum)
            {
                return {dp[i].second,dp[l].second,dp[r].second};
            }
            else if(dp[l].first+dp[r].first>sum)
            {
                r--;
            }
            else l++;
        }
    }

    return {-1,-1,-1};
}
int main()
{
    int n, k; cin>>n>>k;
    vector<int> nums(n);
    for(int i=0; i< n; i++)
    {
        cin>>nums[i];
    }
    vector<int> ans=sol(nums,k);
    if(ans[0]==-1) cout<<"IMPOSSIBLE"<<endl;
    else{
        for(int i=0; i< ans.size(); i++)
        {
            cout<<ans[i]+1<<" ";
        }
    }

}
