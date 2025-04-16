/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main()
{
    int MOD=1e9+7;
    ll n;cin>>n;
   vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
   for(int i=1; i<= n; i++)
   {
       for(int j=1; j<= n; j++)
       {
           char c;cin>>c;
           if(c=='*')
           {
               dp[i][j]=0;
           }
           else
           {
               dp[i][j]=1;
           }
       }
   }
   if(dp[1][1]==0)
   {
       cout<<0<<endl;
       return 0;
   }
   dp[0][1]=1;
   for(ll i=1; i<= n; i++)
   {
       for(ll j=1; j<= n; j++)
       {
           if(dp[i][j]!=0)
           {
               dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
           }

       }
   }
   cout<<dp[n][n]<<endl;
}
