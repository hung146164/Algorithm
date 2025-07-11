#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[21][1001];

int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp,0,sizeof(dp));
    int n,s;cin>>n>>s;
    dp[0][0]=1;
    for(int i=1 ;i<= n; i++ )
    {
        int x; cin>>x;

        for(int j=0;j<=s; j++)
        {
            dp[i][j]+=dp[i-1][j];
            if(j>=x) dp[i][j]+=dp[i-1][j-x];
        }
    }
//    for(int i=0; i<= n; i++)
//    {
//        for(int j=0; j<=s;j++)
//        {
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    if(s==0) cout<<dp[n][s]-1<<endl;
    else cout<<dp[n][s]<<endl;
}
