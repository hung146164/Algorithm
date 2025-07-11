#include<bits/stdc++.h>
using namespace std;
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--)
    {
        int n,m,x,y;cin>>n>>m>>x>>y;
        vector<vector<char>> ans(n,vector<char>(m));
        x--;y--;
        for(int i=0; i< n; i++)
        {
            for(int j=0; j< m; j++)
            {
                if(j==y)
                {
                    if(i<x)
                    {
                        ans[i][j]='v';
                    }
                    else
                    {
                        ans[i][j]='^';
                    }
                }
                else if(j<y)
                {
                    ans[i][j]='>';
                }
                else
                {
                    ans[i][j]='<';
                }
            }
        }

        if(!(x!=0 && x!=n-1 && y!=0 && y!=m-1))
        {
            for(int j=0;j<m-1;j++)
            {
                ans[0][j]='>';
            }
            for(int j=0; j<n-1;j++)
            {
                ans[j][m-1]='v';
            }
            for(int j=1; j<m;j++)
            {
                ans[n-1][j]='<';
            }
            for(int j=1; j<n;j++)
            {
                ans[j][0]='^';
            }
        }
        ans[x][y]='.';
        for(int i=0; i< n; i++)
        {
            for(int j=0; j< m; j++)
            {
                cout<<ans[i][j];
            }
            cout<<'\n';
        }



    }
}
