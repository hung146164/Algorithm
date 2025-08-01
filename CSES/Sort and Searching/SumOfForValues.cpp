#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k; cin>>n>>k;
    vector<pair<int,int>> nums(n);
    for(int i=0; i< n; i++)
    {
        int x; cin>>x;
        nums[i]={x,i};
    }
    sort(nums.begin(), nums.end());

    for(int i=0; i< nums.size(); i++)
    {

    }
}
