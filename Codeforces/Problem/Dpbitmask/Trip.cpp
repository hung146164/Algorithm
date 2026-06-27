#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=1e5+1;

ll maxll(ll a,ll b)
{
    if(a>b) return a;
    return b;
}
ll minll(ll a,ll b)
{
    if(a>b) return b;
    return a;
}
ll gdc(ll a, ll b)
{
    if(b==0) return a;
    return gdc(b,a%b);
}

namespace sub1
{
    bool CheckSub1()
    {
        return true;
    }
    void sol()
    {

    }
}
namespace sub2
{
    bool CheckSub2()
    {
        return true;
    }
    void sol()
    {

    }
}
namespace sub3
{
    bool CheckSub3()
    {
        return true;
    }
    void sol()
    {

    }
}
int sol(int curr, vector<vector<int>>& g,int mask,vector<vector<int>>& dp)
{
    int n=g.size();
    //cout<<"th "<<((1<<n)-1)<<' '<<mask<<'\n';

    if(((1<<n)-1)==mask)
    {
        //cout<<"Da return"<<'\n';
        return 0;
    }
    if(curr!=-1 && dp[curr][mask]!=-1) return dp[curr][mask];
    int ans=INT_MAX;
    for(int i=0; i< n; i++)
    {
        if((mask>>i)&1) continue;
        ans=min(ans,(curr!=-1?g[curr][i]:0)+sol(i,g,mask|(1<<i),dp));
    }
    if(curr!=-1) dp[curr][mask]=ans;
    return ans;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<vector<int>> g(n,vector<int>(n));
    for(int i=0; i< n; i++)
        for(int j=0;j<n; j++)
            cin>>g[i][j];

    vector<vector<int>> dp(n,vector<int>((1<<16),-1));

    cout<<sol(-1,g,0,dp)<<'\n';
}


