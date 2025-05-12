#include<bits/stdc++.h>
using namespace std;
bool issafe(int x,int n)
{
    return x>=0 && x<n;
}
int sol(vector<int> nums)
{
    int ans=0;int n= nums.size();
    priority_queue<pair<int,int>> pq;
    for(int i=0; i< nums.size(); i++)
    {
        pq.push({nums[i],i});
    }
    vector<bool> check(nums.size());
    while(!pq.empty())
    {
        pair<int,int> curr=pq.top();
        pq.pop();
        int pivot=curr.second;
        if(check[pivot]==true) continue;
        //next;
        check[pivot]=true;
        ans++;

        int clonex=pivot+1;
        while(issafe(clonex,n) && !check[clonex] && nums[clonex-1]>=nums[clonex])
        {
            check[clonex]=true;
            clonex++;
        }
        clonex=pivot-1;
        while(issafe(clonex,n) && !check[clonex] && nums[clonex]<=nums[clonex+1])
        {
            check[clonex]=true;
            clonex--;
        }
    }
    return ans;
}
int main(void)
{
    int t;
    cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vector<int>nums;
        for(int i=0; i< n; i++)
        {
            int x; cin>>x;
            nums.push_back(x);
        }
        cout<<sol(nums)<<endl;
    }
}
