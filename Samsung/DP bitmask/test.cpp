#include<bits/stdc++.h>
using namespace std;
int dx[4] {0,0,-1,1};
int dy[4] {-1,1,0,0};
void bfs(int start,vector<vector<char>>& g,vector<pair<int,int>>& p,vector<vector<int>>& to)
{
    int x=p[start].first;
    int y=p[start].second;
    vector<vector<bool>> check(g.size(),vector<bool>(m.size(),false));
    check[x][y]=true;
    queue<pair<int,int>> q;
    q.push({x,y});
    int co=1;
    while(!q.empty())
    {
        int size=q.size();
        for(int _=0; _<size; _++)
        {
            pair<int,int> curr=q.front();
            q.pop();

            for(int i=0; i< 4; i++)
            {
                int tox=curr.first+dx[i];
                int toy=curr.second+dy[i];
                if(tox>=g.size() || toy>=g[0].size() || tox<0 || toy<0) continue;
                if(check[tox][toy] || g[tox][toy]=='x') continue;
                check[tox][toy]=true;
                if(g[tox][toy]=='.')
                {
                    check[tox][toy]=true;
                    q.push({tox,toy});
                    continue;
                }
                for(int j=0; j<p.size(); j++)
                {
                    if(p[i].first==tox&&p[i].second==tox)
                    {
                        to[start][j]=co;
                        to[j][start]=co;
                    }
                }

            }
            co++;
        }

    }
}
int travel(int basex,int basey,vector<vector<int>>& to)
{

}
int sol(vector<vector<char>>& g)
{
    int n=g.size(),m=g[0].size();
    int basex=0,basey=0;
    vector<pair<int,int>> p;
    for(int i=0; i< g.size(); i++)
    {
        for(int j=0; j< g[0].size(); j++)
        {
            if(g[i][j]=='o')
            {
                basex=i;
                basey=j;
            }
            else if(g[i][j]=='*')
            {
                p.push_back({i,j});
            }
        }
    }
    vector<vector<int>> to(p.size(),vector<int>(p.size()));
    for(int i=0; i< p.size(); i++)
    {

        bfs(i,g,p,to);
    }
    return travel(basex,basey,to);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,m;
    while(cin>>n && cin>>m)
    {
        vector<vector<char>> g(n,vector<int>(m));
        for(int i=0; i< n ; i++)
        {
            for(int j=0; j< m; j++)
            {
                cin>>g[i][j];
            }
        }
        cout<<sol(g)<<'\n';
    }
}
