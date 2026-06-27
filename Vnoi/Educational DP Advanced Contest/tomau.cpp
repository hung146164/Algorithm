#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=1e5+1;

pair<int,int> sol(int curr,int white ,vector<vector<int>>& g,int parent=-1)
{
    //den
    int ansden=0;
    int trangpus=0;
    for(int i=0; i< g[curr].size(); i++)
    {
        int to=g[curr][i];
        if(parent==to) continue;
        pair<int,int> kq=sol(to,white,g,curr);
        ansden+=(white+trangpus)*kq.second+kq.first;
        trangpus+=kq.second;
    }
    int anstrang=0;
    for(int i=0; i< g[curr].size(); i++)
    {
        int to=g[curr][i];
        if(parent==to) continue;
        pair<int,int> kq=sol(to,1,g,curr);
        anstrang+=kq.first;
    }

    if(anstrang>ansden)
    {
        return {anstrang,1};
    }
    return {ansden,trangpus};
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vector<vector<int>> g(n+5);
        for(int i=0;i<n-1; i++)
        {
            int a, b; cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        pair<int,int> ans=sol(1,0,g);
        cout<<ans.first<<' '<<ans.second<<'\n';
    }



}


