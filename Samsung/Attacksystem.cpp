#include<bits/stdc++.h>
using namespace std;
const int AX=10000;
int id[AX],low[AX],tplt[AX],lan=0;
void dfs(int curr,int parent,vector<vector<int>>& g)
{
    id[curr]=low[curr]=++lan;
    int cnt=0;
    for(auto i: g[curr])
    {
        if(i==parent) continue;
        if(id[i]!=0)
        {
            low[curr]=min(low[curr],id[i]);
        }
        else{
            dfs(i,curr,g);
            low[curr]=min(low[curr],low[i]);

            if(low[i]>=id[curr]) cnt++;

        }
    }
    tplt[curr]=cnt;

}
int main()
{
    int n,m; cin>>n>>m;
    vector<vector<int>> g(n);
    memset(tplt,0,sizeof(tplt));
    memset(id,0,sizeof(id));
    memset(low,INT_MAX,sizeof(low));

    for(int i=0; i< m; i++)
    {
        int a,b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(0,-1,g);
    for(int i=0; i< 10 ; i++)
    {
        cout<<id[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i < 10; i++)
    {
        cout<<low[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i< 10 ; i++)
    {
        cout<<tplt[i]<<" ";
    }
    cout<<endl;
    int ans=0;
    int maxx=0;
    for(int i=0; i< n; i++)
    {
        if(tplt[i]>maxx)
        {
            maxx=tplt[i];
            ans=i;
        }
    }
    cout<<"khop la: "<<ans<<endl;


}
