#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
int dx[4]{0,0,1,-1};
int dy[4]{-1,1,0,0};

int anhet(int x,int y, vector<vector<bool>>& check, vector<vector<int>>& nums)
{
    int ans=0;
    for(int i=0; i< 4; i++)
    {
        int tox=x+dx[i];
        int toy=y+dy[i];
        if(tox<0 || toy<0 || tox>=check.size() || toy>=check[0].size()) continue;
        if(check[tox][toy] || nums[tox][toy]==0) continue;
        check[tox][toy]=true;
        ans++;
        ans+=anhet(tox,toy,check,nums);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t;
    int c=1;
    while(t--)
    {
        int n,m; cin>>n>>m;
        vector<vector<int>> nums(n,vector<int>(m));
        for(int i=0; i< n; i++)
        {
            for(int j=0; j< m ;j++)
            {
                cin>>nums[i][j];
            }
        }
        vector<vector<bool>> check(n,vector<bool>(m,false));
        int ans=0;
        for(int i=0; i< n; i++)
        {
            for(int j=0; j< m; j++)
            {
                if(!check[i][j]&& nums[i][j]==1)
                {
                    check[i][j]=true;
                    ans=max(ans,anhet(i,j,check,nums)+1);
                }
            }
        }
            cout<<"Case #"<<c<<": "<<ans<<'\n';
        c++;
    }
    return 0;
}
//2
//6 5
//0 0 0 1 0
//0 1 0 0 0
//0 0 1 1 0
//0 1 0 0 1
//0 0 0 0 1
//1 1 0 1 0
//7 5
//0 0 0 0 0
//0 1 0 0 1
//0 0 1 1 0
//0 0 0 1 0
//0 1 0 1 0
//0 0 1 0 1
//1 0 0 1 0

//1
//8 8
//1
