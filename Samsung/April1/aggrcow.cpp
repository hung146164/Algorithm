#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n,k; cin>>n>>k;

        vector<int> nums;
        for(int i=0; i< n;i ++)
        {
            int x; cin>>x;
            nums.push_back(x);
        }

        sort(nums.begin(), nums.end());

        int l=1,r=1e9+1;
        while(l<=r)
        {
             int m=l+(r-l)/2;
            //8cout<<m<<'\n';

            int co=0;
            int pre=0;
            for(int i=0; i< n; i++)
            {
                if(i==0 || nums[i]-pre>=m)
                {
                    co++;
                    pre=nums[i];
                }
            }
            if(co>=k)
            {
                l=m+1;
            }
            else
            {
                r=m-1;
            }
        }
        cout<<r<<'\n';

    }
}
