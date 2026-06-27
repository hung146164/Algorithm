#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool sol()
{
    int n;cin>>n;
    vector<int> nums;
    for(int i=0; i< n;i++)
    {
        int x; cin>>x;
        if(x==n) x--;
        nums.push_back(x);
    }
//    for(auto i: nums) cout<<i<<' ';
//    cout<<'\n';

    for(int i=2; i<=n; i++)
    {
        bool have=false;
        unordered_map<int,int> dp;
        for(int j=0;j<n;j++)
        {
            dp[nums[j]]++;
            if(j-i>=0)
            {
                dp[nums[j-i]]--;
                if(dp[nums[j-i]]==0)
                {
                    dp.erase(nums[j-i]);
                }
            }
//            cout<<j<<' '<<dp.size()<<" h \n";
            if(dp.size()==1 && j>=i-1)
            {
                for(int k=j-i+1;k<=j;k++)
                {
                    nums[k]--;
                }
                have=true;
                break;
            }
        }
        if(!have)
        {
//            cout<<"YEE "<<i<<'\n';
            return false;
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--)
    {
        cout<<(sol()?"YES":"NO")<<'\n';
    }
}
