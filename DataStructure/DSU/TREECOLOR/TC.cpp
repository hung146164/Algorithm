#include<bits/stdc++.h>
using namespace std;
set<int>* dfs(int curr, vector<int>& ans,vector<vector<int>>& gra,vector<int>& color,vector<bool>& check)
{
    set<int>* cc=new set<int>();
    check[curr]=true;
    cc->insert(color[curr]);
    for(int i=0; i< gra[curr].size(); i++)
    {
        if(check[gra[curr][i]]) continue;
        set<int>* newset= dfs(gra[curr][i],ans,gra,color,check);
        if(newset->size()>cc->size())
        {
            swap(cc,newset);
        }
         for(auto i: *newset) cc->insert(i);
         delete newset;
    }
    ans[curr]=cc->size();
    return cc;
}
int main()
{
      ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;
    vector<vector<int>> gra(n+1);
    vector<int> color(n+1);
    for(int i=0; i< n-1; i++)
    {
        int x, y; cin>>x>>y;
        gra[x].push_back(y);
        gra[y].push_back(x);
    }
    for(int i=1; i<=n ;i++)
    {
        int x; cin>>x;
        color[i]=x;
    }
    vector<bool> check(n+1);
    vector<int> ans(n+1);
    set<int>* root = dfs(1, ans, gra, color, check);
    delete root;

    for(int i=1; i<=n; i++)
    {
        cout<<ans [i]<<endl;
    }
}
