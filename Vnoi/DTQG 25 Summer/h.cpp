#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, s; cin>>n>>s;
    vector<int> nums;
    for(int i=0; i< n; i++)
    {
        int x; cin>>x;
        nums.push_back(x);
    }
    vector<int> dp(s+1,-1);
    dp[0]=0;
    for(int i=0; i<n; i++)
    {
        for(int j=s;j>=nums[i];j--)
        {
            if(dp[j]!=-1) continue;
            if(dp[j-nums[i]]!=-1)
            {
                dp[j]=i;
            }
        }
    }
//    for(int i=0; i< dp.size(); i++)
//    {
//        cout<<dp[i]<<" ";
//    }
//    cout<<endl;
    int curr=s;
    if(dp[curr]==-1) cout<<-1<<endl;
    else{
        vector<int> ans;
        while(curr>0)
        {
           // cout<<curr<<" "<<nums[dp[curr]]<<endl;
            ans.push_back(dp[curr]);
            curr-=nums[dp[curr]];

        }
        cout<<ans.size()<<'\n';
        for(int i=0; i< ans.size(); i++)
        {
            cout<<ans[i]+1<<' ';
        }
    }

}
