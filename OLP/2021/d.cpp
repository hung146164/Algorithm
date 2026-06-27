#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=1e5+1;

int maxll(int a,int b)
{
    if(a>b) return a;
    return b;
}
int minll(int a,int b)
{
    if(a>b) return b;
    return a;
}
int gdc(int a, int b)
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
int dp[400][400][400][2];
int n,x,k;
int sol(int curr,int pre,int k, bool prehigh)
{
    if(curr==n)
    {
        if(k==0) return 1;
        return 0;
    }
    if(dp[curr][pre][k][prehigh] !=-1) return dp[curr][pre][k][prehigh] ;
    int ans=0;
//    for(int i=0; i< x; i++)
//    {
//        ans=(1LL*ans+sol(curr+1,i,k-((prehigh && pre>i)?1:0),i>pre))%mod;
//    }
    if(prehigh)
    {
        ans=(1LL* ans+ (pre)*sol(curr+1,i,k-1,false))%mod;
    }
    else{
        ans=(1LL* ans+(x-1-pre)*sol(curr+1,i,k,true))%mod;
        ans=(1LL* ans+(pre+1)*sol(curr+1,i,k,false))%mod;
    }
    return dp[curr][pre][k][prehigh] =ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=0; i< 400; i++)
    {
        for(int j=0; j< 400; j++)
        {
            for(int k=0; k< 400; k++)
            {
                for(int h=0; h<2; h++)
                {
                    dp[i][j][k][h]=-1;
                }
            }
        }
    }
    cin>>n>>x>>k;
    cout<<sol(0,x,k,false)<<'\n';
}
