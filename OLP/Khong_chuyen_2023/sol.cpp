#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll u,v; cin>>u>>v;

    ll ans= u*u+v*v;
    cout<<ans/4;
    cout<<'.';
    if(ans%4==1)
    {
        cout<<25<<'\n';
    }
    else if(ans%4==2) cout<<50<<'\n';
    else if(ans%4==3) cout<<75<<'\n';
    else cout<<"00"<<'\n';
}
