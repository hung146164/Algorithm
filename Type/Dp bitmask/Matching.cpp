#include <bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
main()
{
    int n;
    cin>>n;
    vector<vector<bool>>a(n,vector<bool>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            bool x;
            cin>>x;
            a[i][j]=x;
        }
    }
    vector<int>dp(1<<n,0);
    dp[0]=1;
    for(int i=1;i< 1<<n ;i++)
    {
        for(int j=0;j<n;j++)
        {
            if((i & (1<<j))!=0 && a[j][__builtin_popcount(i)-1])
            {
                dp[i]+= dp[ i ^ (1<<j) ];
                dp[i]%=mod;
            }
        }
    }
    cout<<dp[ (1<<n)-1 ];
}
