#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<pair<int,int>>> duong;
vector<vector<int>> g;
vector<int> h;
int n;
int t;
void bfs(int in)
{
    vector<bool> check(n+1,false);
    check[in]=true;

    queue<vector<int>> q;
    q.push({in,0,h[in]});
    while(!q.empty())
    {
        //ht, dodai, chieu cao max
        vector<int> curr=q.front();
        q.pop();
        int from =curr[0];
        int len=curr[1];
        int hei=curr[2];
        duong[in][from]={len,hei};
        for(int i=0; i< g[from].size(); i++)
        {
            int to=g[from][i];
            if(!check[to])
            {
                check[to]=true;
                q.push({to,len+1,max(hei,h[to])});
            }
        }
    }
}
int sol()
{
    ll ans=0;
    for(int i=1; i<= n; i++)
    {
        for(int j=i+1; j<= n ;j++)
        {
            for(int k=j+1; k<= n; k++)
            {
                if(max({duong[i][j].second,duong[j][k].second,duong[k][i].second})==t)
                {
                    ans+=1LL*duong[i][j].first+duong[k][i].first+duong[j][k].first;
                }
            }
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>t;
    g.resize(n+1);
    duong.resize(n+1,vector<pair<int,int>>(n+1));
    h.push_back(0);
    for(int i=0; i< n; i++)
    {
        int x; cin>>x;
        h.push_back(x);
    }

    for(int i=0; i< n-1; i++)
    {
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1; i<= n; i++)
    {
        bfs(i);
    }
    cout<<sol()<<'\n';

}
