#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;

    unordered_map<int,vector<int>> dp;
    vector<int> nums;
    for(int i=0; i< n; i++)
    {
        int x; cin>>x;
        nums.push_back(x);
    }
    for(int i=0; i< n; i++)
    {
        for(int j=0; j< n; j++)
        {
            int sum=3*nums[i]-nums[j];
            dp[sum].push_back(j);
        }
    }
    int ans=0;
    vector<bool> check(1e5);

    for(int i=0;i<n; i++)
    {
        for(int j=i+1; j< n; j++)
        {
            int sum=nums[i]+nums[j];
            for(auto k: dp[sum])
            {
                if(k!=i && k!=j)
                {
                    if(check[sum+nums[k]]) break;
                   // cout<<i<<' '<<j<<' '<<k<<'\n';
                    ans++;
                    check[sum+nums[k]]=true;
                    break;
                }
            }
            if(dp.find(sum)!=dp.end()) dp.erase(sum);
        }
    }
    cout<<ans<<'\n';
}
