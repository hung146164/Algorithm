#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=1e5+1;

ll maxll(ll a,ll b)
{
    if(a>b) return a;
    return b;
}
ll minll(ll a,ll b)
{
    if(a>b) return b;
    return a;
}
ll gdc(ll a, ll b)
{
    if(b==0) return a;
    return gdc(b,a%b);
}

bool check(pair<int,int>& nguoi, vector<pair<int,int>> dagiac)
{
    int bang=0;
    int rieng=0;
    for(int i=1; i< dagiac.size(); i++)
    {
        int ax=dagiac[i-1].first;
        int ay=dagiac[i-1].second;
        int bx=dagiac[i].first;
        int by=dagiac[i].second;
        double x= 1.0*(bx-ax)*(nguoi.second-ay)/(by-ay) + ax;
        if(x>=nguoi.first)
        {
            if(x==ax || x== bx) bang++;
            else if(ax<x && x< bx) rieng++;
        }

    }
    int val=bang/2+rieng;
    if(val%2==0) return false;
    return true;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; cin>>n>>m;

    vector<pair<int,int>> nguoi;
    for(int i=0; i< m; i++)
    {
        int a, b; cin>>a>>b;
        nguoi.push_back({a,b});
    }

    vector<vector<pair<int,int>>> g(n);
    for(int i=0; i< n ;i++)
    {
        int c; cin>>c;
        for(int j=0; j< c; j++)
        {
            int a, b; cin>>a>>b;
            g[i].push_back({a,b});
        }
        g[i].push_back(g[i][0]);
    }
    vector<int> ans(n);
    for(int i=0; i< m; i++)
    {
        for(int j=0; j< n; j++)
        {
            if(check(nguoi[i],g[j]))
            {
                ans[j]++;
                break;
            }
        }
    }
    int maxx=0;
    cout<<"ANS:"<<'\n';
    for(int i=0; i< ans.size(); i++){
        maxx=max(ans[i],maxx);
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
    cout<<maxx<<'\n';
}


