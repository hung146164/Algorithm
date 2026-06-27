#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+5;
const int mod=1e9+7;
const int inf=1e9;
int dp[12][1<<12];
int n,m;
vector<int> minc(12,inf);
int sol(vector<vector<int>>& a,int curr,int mask)
{
    if(curr==n)
    {
        int ans=0;
        for(int j=0; j< m; j++)
        {
            if((mask>>j)&1) continue;
            ans+=minc[j];
        }
        return ans;
    }
    if(dp[curr][mask]!=-1) return dp[curr][mask];
    int ans=inf;

    for(int i=0; i<m; i++)
    {
        ans=min(ans,a[curr][i]+sol(a,curr+1,mask|(1<<i)));
    }
    return dp[curr][mask]=ans;
}
void solve()
{
    memset(dp,-1,sizeof(dp));
     cin>>n>>m;

     if(n>m)
     {
        swap(n,m);
        vector<vector<int>> a(n,vector<int>(m));
        for(int j=0; j<m;j++)
            {
            for(int i=0;i<n; i++)
            {

                cin>>a[i][j];
                minc[j]=min(a[i][j],minc[j]);
            }
        }
//        for(int i=0; i< n;i++)
//        {
//            for(int j=0;j<m;j++)
//            {
//                cout<<a[i][j]<<' ';
//            }
//            cout<<'\n';
//        }
        cout<<sol(a,0,0)<<'\n';
     }
     else{
        vector<vector<int>> a(n,vector<int>(m));
        for(int i=0; i< n; i++)
        {
            for(int j=0; j<m;j++)
            {
                cin>>a[i][j];
                minc[j]=min(a[i][j],minc[j]);
            }
        }
        cout<<sol(a,0,0)<<'\n';
     }
}

signed main()
{
    solve();
}









