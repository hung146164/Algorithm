#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=4e7+1;
ll dp[N];
ll sol(int n)
{
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    for(int i=3; i<=n; i++)
    {
        dp[i]=dp[i-1]+(i%3==0?0:dp[i/2+i%3]);
    }
    cout<<'\n';
    return dp[n];
}
int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(dp,0,sizeof(dp));
    cout<<"Nhap n = ";
    int n; cin>>n;
    cout<<"f("<<n<<")"<<" = "<<sol(n)<<'\n';

}
