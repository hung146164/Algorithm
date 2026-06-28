#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+5;
const int mod=1e9+7;

int nums[105][105];
bool check[105][105];
int dx[]{0,0,-1,1};
int dy[]{-1,1,0,0};
int n,m;
int sol(int x,int y)
{
    if(check[x][y])
    {
        return 0;
    }
    if(x<0 || x>=n || y<0 || y>=m || nums[x][y]==0)
    {
        return 1;
    }
    check[x][y]=true;
    int ans=0;
    for(int i=0;i<4;i++)
    {
        ans+=sol(x+dx[i],y+dy[i]);
    }
    return ans;

}
void solve()
{
     cin>>n>>m;
    for(int i=0; i< n; i++)
    {

        for(int j=0; j<m; j++)
        {
            cin>>nums[i][j];
        }
    }

    int ans=0;
    for(int i=0; i< n; i++)
    {
        for(int j=0; j<m ;j++)
        {
            if(nums[i][j]==1 && !check[i][j])
            {
                ans+=sol(i,j);
            }
        }
    }
    cout<<ans<<'\n';
}

signed main()
{
    solve();
}









