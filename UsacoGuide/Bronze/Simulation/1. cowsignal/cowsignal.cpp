#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("cowsignal.in","r",stdin);
    freopen("cowsignal.out","w",stdout);

    int m,n,k;
    cin>>m>>n>>k;
    vector<vector<char>> dp(m,vector<char>(n));
    for(int i=0; i< m ;i++)
    {
        for(int j=0; j< n; j++)
        {
            cin>>dp[i][j];

        }
    }
    for(int i=0; i< m ;i++)
    {
        for(int t1=0; t1<k; t1++)
        {
            for(int j=0; j< n; j++)
            {
                for(int t1=0; t1<k; t1++)
                {
                    cout<<dp[i][j];
                }
            }
            cout<<endl;
        }

    }

}
