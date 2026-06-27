#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=4e7+1;
unordered_map<ll,ll> dp;
ll sol(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    if(n==2) return 2;
    if(dp[n]!=0) return dp[n];
    ll a=n%3;
    ll ans=0;
    if(a==0)
    {
        ans= sol(n/3 *2);
    }
    else if(a==1)
    {
        ll nn=(n-1)/3;
        ans= sol(2*nn)+sol(2*nn+1);
    }
    else{
        ll nn=(n-2)/3;
        ans=sol(2*nn)+sol(2*nn+1)+sol(2*nn+2);
    }
    return dp[n]=ans;
}
int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    memset(dp,-1,sizeof(dp));
    cout<<"Nhap n = ";
    int n; cin>>n;
    cout<<"f("<<n<<")"<<" = "<<sol(n)<<'\n';
}
