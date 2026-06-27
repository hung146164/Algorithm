#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int N=1e5+1;

int sol(vector<vector<int>>& dp,int n)
{
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            ans=max(ans,dp[i][j]+dp[i-1][j]+dp[i][j-1]+dp[i+1][j]+dp[i][j+1]);
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vector<vector<int>> dp(n+2,vector<int>(n+2));
        int cnt=1;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<= n; j++)
            {
                dp[i][j]=cnt;
                cnt++;
            }
        }
        cout<<sol(dp,n)<<'\n';
    }
}
