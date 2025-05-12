#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n, x; cin>>n>>x;

    int sum=0;
    vector<int> nums;
    for(int i=0; i< n; i++)
    {
        int k ; cin >> k;
        nums.push_back(k);
    }
    int ans=0;
    for(int r=0,l=0; r<n; r++)
    {
        sum+=nums[r];
        while(sum>x)
        {
            sum-=nums[l];
            l++;
        }
        if(sum==x) ans++;
    }
    cout<<ans<<endl;
}
