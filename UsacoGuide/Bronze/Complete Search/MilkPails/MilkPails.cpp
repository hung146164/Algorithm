#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("pails.in","r",stdin);
    freopen("pails.out","w",stdout);

    int m,n,k;
    cin>>m>>n>>k;
    vector<vector<char>> dp(m,vector<char>(n));
    for(int i=0; i< m ;i++)
    {
        for(int j=0; j< n; j++)
        {
            cin>>dp[i][j];
            for(int t=0; t< k ;t++)
            {
                cout<<dp[i][j];
            }
        }
        cout<<endl;
    }

}
