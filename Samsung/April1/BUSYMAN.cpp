#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vector<vector<int>> nums;
        for(int i=0; i< n; i++)
        {
            int x, y;cin>>x>>y;
            nums.push_back({x,y});
        }
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=1; i<nums.size()-1 ;i++)
        {
            if(nums[i][0]>=nums[i-1][1] && nums[i][1]<=nums[i+1][0]) ans++;
        }
        cout<<ans<<'\n';



    }
}
