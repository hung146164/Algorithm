#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int N=1e5+1;
int dp[N][3];
int sol(int& n, int curr=0,int ht=0)
{
    if(curr==n) return 1;
    if(dp[curr][ht]!=-1) return dp[curr][ht];
    int ans=0;
    if(ht==0)
    {
        ans=(ans+1LL*sol(n,curr+1,0))%mod;
        ans=(ans+1LL*sol(n,curr+1,1))%mod;
    }
    else if(ht==1)
    {
        ans=(ans+1LL*sol(n,curr+1,1));
        ans=(ans+1LL*sol(n,curr+1,2));
    }
    else{
        ans=(ans+1LL*sol(n,curr+1,2));
    }
    return dp[curr][ht]=ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(dp,-1,sizeof(dp));
    int n;cin>>n;
    cout<<sol(n,0,0)+sol(n,0,1)+sol(n,0,2)<<'\n';

}
