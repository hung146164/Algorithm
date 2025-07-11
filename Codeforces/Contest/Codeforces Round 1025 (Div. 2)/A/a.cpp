#include<bits/stdc++.h>
using namespace std;
bool sol(vector<int>& nums)
{
    int c=0;
    if(nums[0]==0) c++;
    for(int i=1; i<nums.size(); i++)
    {
        if(nums[i]==nums[i-1] && nums[i]==0) return true;
        if(nums[i]==0) c++;
    }
    return c==0?true:false;
}
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n ;cin>>n;
        vector<int>nums;
        for(int i=0; i< n; i++)
        {
            int x; cin>>x;
            nums.push_back(x);
        }
        cout<<(sol(nums)?"YES":"NO")<<endl;
    }
}
