#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    int c=1;
    while(t--)
    {
        int n ;
        cin>>n;
        vector<int> nums;
        for(int i=0; i< n; i++)
        {
            int x;
            cin>>x;
            nums.push_back(x);
        }
        int max1=-1, max2=-1;
        for(int i=0; i< nums.size(); i++)
        {
            if(nums[i]>max1)
            {
                max2=max1;
                max1=nums[i];
            }
            else if(nums[i]>max2 && nums[i]!=max1)
            {
                max2=nums[i];
            }
        }
        //cout<<max1<<' '<<max2<<'\n';
        if(max2==-1) cout<<"Case #"<<c<<": "<<max1<<'\n';
        else cout<<"Case #"<<c<<": "<<max2<<'\n';
        c++;
    }

    return 0;
}
