#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void dfs(int curr,vector<vector<pair<int,int>>>& m,vector<int>& ans,vector<bool>& check,int d=0)
{
    check[curr]=true;
    ans[curr]=d;
    for(auto i:m[curr])
    {
        if(check[i.first]) continue;
        if(i.second>0)
        {
            dfs(i.first,m,ans,check,d-1);
        }
        else dfs(i.first,m,ans,check,d+1);
    }
   // cout<<'\n';
}
bool cmp(pair<int,int>& a,pair<int,int> & b)
{
    return a.second<b.second;
}
void sol()
{
    int n; cin>>n;
    vector<vector<pair<int,int>>> m(n+1);
    for(int i=0;i<n-1; i++)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int curr=c-d;

        m[a].push_back({b,curr});
        m[b].push_back({a,-curr});
    }
    vector<int> ans(n+1);
    vector<bool> check(n+1);
    dfs(1,m,ans,check);
    vector<pair<int,int>> cc;
    for(int i=1; i< ans.size(); i++)
    {
        cc.push_back({ans[i],i});
    }
    sort(cc.begin(),cc.end());
    for(int i=0; i<cc.size(); i++)
    {
        cc[i].first=i+1;
    }
    sort(cc.begin(),cc.end(),cmp);
    for(auto i:cc) cout<<i.first<<' ';
    cout<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--)
    {
        sol();
    }
}
