#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("speeding.cpp","r",stdin);
    freopen("speeding.cpp","w",stdout);

    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> a,b;
    a.push_back({0,0});
    b.push_back({0,0});
    for(int i=0; i< n; i++)
    {
        int x,y;cin>>x>>y;
        a.push_back({x,y});
    }
      for(int j=0; j< m; j++)
    {
        int x,y;cin>>x>>y;
        b.push_back({x,y});
    }

    int ans=0;
    int l=1;
    int r=1;
    while(l<n && r<m)
    {
        if(a[l-1]<=b[r] || a)
    }


}
