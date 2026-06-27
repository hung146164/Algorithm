#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=1e5+1;
int dp[16][(1<<17)];
int sol(int i,int mask,vector<vector<int>>& g)
{
    //cout<<"DB "<<i<<' '<<g.size()<<endl;
    if(i==g.size()) return 0;
    //cout<<"DBb "<<dp[i][mask]<<endl;
    if(dp[i][mask]!=-1) return dp[i][mask];
    int ans=0;
    for(int j=0; j<g.size() ;j++)
    {
        if( (mask>>j) &1) continue;
        mask|=(1<<j);

        ans=max(ans,g[i][j]+sol(i+1,mask,g));
        mask^=(1<<j);

    }

    return dp[i][mask]=ans;
}
void reset()
{
    for(int i=0; i<16; i++)
    {
        for(int j=0;j<(1<<16);j++)
        {
            dp[i][j]=-1;
        }
    }
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    for(int k=1;k<=t; k++)
    {
        reset();
        int n; cin>>n;
        vector<vector<int>> g(n,vector<int>(n));
        for(int i=0; i< n; i++)
        {
            for(int j=0; j< n; j++)
            {
                cin>>g[i][j];
            }
        }

        cout<<"Case "<<k<<":"<<' '<<sol(0,0,g)<<'\n';
        //sol(0,0,g);

    }


}


