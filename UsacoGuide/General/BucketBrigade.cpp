#include<bits/stdc++.h>
using namespace std;
int dx[4]{0,-1,0,1};
int dy[4]{-1,0,1,0};
int find(int bx,int by,int rx,int ry,vector<vector<char>>& m)
{
    vector<vector<bool>> check(10,vector<bool>(10));

    queue<pair<int,int>> q;
    q.push({bx,by});
    int c=0;
    while(!q.empty())
    {
        int size=q.size();
        for(int j=0; j<size;j++)
        {

            pair<int,int> curr=q.front();
            q.pop();
            if(curr.first==rx && curr.second==ry) return c;
            for(int i=0; i< 4; i++)
            {
                int x=curr.first+dx[i];
                int y=curr.second+dy[i];
                if(x>=0 && x<10 && y<10 && y>=0 && !check[x][y] && m[x][y]!='R')
                {
                    check[x][y]=true;
                    q.push({x,y});
                }
            }

        }
        c++;
    }

    return -1;
}
int main()
{
    freopen("buckets.in","r",stdin);
    freopen("buckets.out","w",stdout);

    int bx,by,lx,ly;
    vector<vector<char>>m(10,vector<char>(10));
    for(int i=0; i<10; i++)
    {
        for(int j=0; j< 10; j++)
        {
            char c;
            cin>>c;
            m[i][j]=c;
            if(c=='B')
            {
                bx=i;by=j;
            }
            if(c=='L')
            {
                lx=i;ly=j;
            }
        }
    }
    cout<<find(bx,by,lx,ly,m)-1<<'\n';
}



