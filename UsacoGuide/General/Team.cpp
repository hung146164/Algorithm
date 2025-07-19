#include<bits/stdc++.h>
using namespace std;
int main()
{
//    freopen("teleport.in","r",stdin);
//    freopen("teleport.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;cin>>n;
    int ans=0;
    for(int i=0; i<n; i++)
    {
        int c=0;
        for(int j=0; j< 3; j++)
        {
            int x; cin>>x;
            if(x==1) c++;
        }
        if(c>1) ans++;
    }
    cout<<ans<<'\n';


}

