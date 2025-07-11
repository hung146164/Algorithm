#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin>>t;
    while(t--)
    {
        int n,len;cin>>n>>len;
        vector<pair<int,int>> fi{{len,0},{0,len},{0,0},{len,len}};
        int ans=0;
        for(int i=0; i< n; i++)
        {
            int a, b, c,d; cin>>a>>b>>c>>d;
            bool check=false;
            for(int i=0; i< fi.size(); i++)
            {
                if((fi[i].first-c)*a == (fi[i].second-d)*b) check=true;
            }
            if(check) ans++;
        }
        cout<<ans<<'\n';
    }
}
