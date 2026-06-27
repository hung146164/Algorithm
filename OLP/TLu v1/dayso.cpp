#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> nums;
    int n ;cin>>n;
    for(int i=0; i <n; i++)
    {
        int x; cin>>x;
        nums.push_back(x);
    }
    vector<int> v1(nums.size());
    v1[0]=nums[0];
    for(int i=1; i< nums.size(); i++)
    {
        v1[i]=max(v1[i-1],nums[i]);
    }
    vector<int> v2(nums.size());
    v2[1]=nums[0]+nums[1]*2;
    for(int i=2;i<nums.size(); i++)
    {
        v2[i]=max(v2[i-1],2*nums[i]+v1[i-1]);
    }
    vector<int> v3(nums.size());
    v3[2]=nums[0]+nums[1]*2+nums[2]*3;
    int ans=v3[2];
    for(int i=3; i< nums.size(); i++)
    {

        v3[i]=max(v3[i-1],3*nums[i]+v2[i-1]);
        ans=max(ans,v3[i]);
    }
    cout<<ans<<'\n';
}
