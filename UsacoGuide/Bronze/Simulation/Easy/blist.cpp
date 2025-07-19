#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("blist.in","r",stdin);
    freopen("blist.out","w",stdout);

    vector<pair<int,int>> a;
    vector<pair<int,int>> b;
    int n; cin>>n;
    for(int i=0; i< n;i++)
    {
        int x,y,z;cin>>x>>y>>z;
        a.push_back({x,z});
        b.push_back({y,z});
    }
    sort(a.begin(),a.end());
    sort(b.begin(), b.end());

    int l=0;
    int c=0;
    int ans=0;
    for(int i=0; i< a.size();i++)
    {
        c+=a[i].second;
        while(l<n && b[l].first<=a[i].first)
        {
            c-=b[l].second;
            l++;
        }
        ans=max(ans,c);
    }
    cout<<ans<<'\n';
}


