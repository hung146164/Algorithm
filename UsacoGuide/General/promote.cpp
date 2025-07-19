#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("promote.in","r",stdin);
    freopen("promote.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a,b,c,d,e,f,g,h;cin>>a>>b>>c>>d>>e>>f>>g>>h;

    int x=h-g;
    int y=x+f-e;

    int z=y+d-c;
    cout<<z<<'\n'<<y<<'\n'<<x<<'\n';

}



