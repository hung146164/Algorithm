#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m ; cin>>n>>m;
    vector<vector<pair<int,int>>> g(n+1);
    for(int i=0; i< m ;i++)
    {
        int a,b, c;cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=0; i< g[1].size(); i++)
    {
        pq.push({g[1][i].second,g[1][i].first});
    }
     vector<bool> check(n+1);
    check[1]=true;
    ll ans=0;
    while(!pq.empty())
    {
       auto curr=pq.top();
       pq.pop();
       if(check[curr.second]) continue;
       check[curr.second]=true;
       ans+=curr.first;
       for(int i=0; i< g[curr.second].size(); i++)
       {
           pq.push({g[curr.second][i].second,g[curr.second][i].first});
       }
    }
    cout<<ans<<'\n';
}
