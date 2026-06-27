#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=1e7+1;

void maskon(int& mask, int index)
{
    mask |= (1<<index);
}
void maskoff(int& mask,int index)
{
    mask ^= (1<<index);
}
int dp[1<<16][16];
void process()
{
    for(int i=0; i< (1<<16);i++)
    {
        for(int j=0; j< 16; j++)
        {
            dp[i][j]=-1;
        }
    }
}
int n;
int sol(vector<vector<int>>& nums, int mask,int curr)
{
//    cout<<curr<<' '<<mask<<endl;
    if(mask==(1<<n)-1) return 0;
    if(dp[mask][curr]!=-1) return dp[mask][curr];
    int ans=1e9;
    for(int i=0;i<n; i++)
    {
        if(!((mask>>i)&1))
        {

            ans=min(ans,nums[curr][i]+sol(nums,mask|(1<<i),i));

        }
    }
    return dp[mask][curr]=ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    process();
     cin>>n;
    vector<vector<int>> nums(n,vector<int>(n));
    for(int i=0; i< n;i ++)
    {
        for(int j=0; j< n; j++)
        {
            cin>>nums[i][j];
        }
    }
//    cout<<mask<<'\n';
//    cout<<mask<<'\n';
    int ans=1e9;
    for(int i=0; i<n; i++)
    {
        ans=min(ans,sol(nums,(1<<i),i));
    }
    cout<<ans<<'\n';

}


