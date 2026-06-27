#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin>>n;
    vector<int> nums;
    int sum=0;
    for(int i=0; i< n; i++)
    {
        int x; cin>>x;
        sum+=x;
        nums.push_back(x);
    }
    sort(nums.begin(), nums.end());
    int ans=0;
    for(int i=nums.size()-1;i>0 ;i--)
    {
        sum-=nums[i];
        ans+=nums[i]*i-sum;
    }
    cout<<ans<<'\n';
}
