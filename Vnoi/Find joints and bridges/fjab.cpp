#include<bits/stdc++.h>
using namespace std;
const int nMAX=1e4+1;
int id[nMAX],low[nMAX],t,bridge[nMAX],ad[nMAX];

void dfs(int curr,int parent, vector<vector<int>>& g)
{
    id[curr]=low[curr]=++t;
    int khop=0,cau=0;
    int db=0;
    for(auto child : g[curr])
    {
        if(child==parent) continue;
        if(id[child]!=0)
        {
            low[curr]=min(low[curr],id[child]);
        }
        else{

            dfs(child,curr,g);
            low[curr]=min(low[curr],low[child]);
            if(low[child]>=id[curr]) khop++;
            if(low[child]>id[curr]) cau++;
            db++;
        }
    }
    if(parent==-1)
    {
        ad[curr]=db>1?1:0;
        bridge[curr]=cau;
    }
    else{
        bridge[curr]=cau;
        ad[curr]=khop>0?1:0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(low,INT_MAX,sizeof(low));
    memset(bridge,0,sizeof(bridge));
    memset(ad,0,sizeof(ad));
    int n,m; cin>>n>>m;
    vector<vector<int>> g(n);
    for(int i=0; i< m ; i++)
    {
        int a,b;cin>>a>>b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
        for (int i = 0; i < n; ++i) {
        if (id[i] == 0) { // If not visited
            dfs(i, -1, g);
        }
    }
//    cout<<endl;
//    cout<<"id"<<endl;
//    for(int i=0; i< 12 ;i ++)
//    {
//        cout<<id[i]<<" ";
//    }
//    cout<<endl;
//    cout<<"low"<<endl;
//    for(int i=0; i< 12 ;i ++)
//    {
//        cout<<low[i]<<" ";
//    }
//    cout<<endl;
//    cout<<"cau"<<endl;
//    for(int i=0; i< 12 ;i ++)
//    {
//        cout<<bridge[i]<<" ";
//    }
//    cout<<endl;
//    cout<<"canh"<<endl;
//    for(int i=0; i< 12 ;i ++)
//    {
//        cout<<ad[i]<<" ";
//    }
//    cout<<endl;
    int cau=0;
    int node=0;
    for(auto i: bridge) cau+=i;
    for(auto i: ad) node+=i;
    cout<<node<<" "<<cau<<'\n';
}
