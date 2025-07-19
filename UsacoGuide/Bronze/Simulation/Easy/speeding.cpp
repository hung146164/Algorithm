#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("speeding.in","r",stdin);
    freopen("speeding.out","w",stdout);

    int n,m; cin>>n>>m;
    vector<pair<int,int>> a,b;
    int p=0;
    for(int i=0; i< n; i++)
    {
        int x,y; cin>>x>>y;
        p+=x;
        a.push_back({p,y});
    }
    p=0;
    for(int i=0; i< m; i++)
    {
        int x,y; cin>>x>>y;
        p+=x;
        b.push_back({p,y});
    }
    int l=0,r=0;
    int pivot=0;
    int ans=0;
    while(l<n && r<m)
    {
        while(l<n && a[l].first<=pivot)
        {
            l++;
        }
        while(r<m && b[r].first<=pivot)
        {
            r++;
        }
        if(l<n && r<m)
        {
            if(a[l].first<b[r].first)
            {
                ans=max(ans,b[r].second-a[l].second);
                pivot=a[l].first;
            }
            else{
                ans=max(ans,b[r].second-a[l].second);
                pivot=b[r].first;
            }
            //cout<<ans<<endl;
        }
    }
    cout<<ans<<'\n';
}
