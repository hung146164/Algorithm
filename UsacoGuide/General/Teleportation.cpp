#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("teleport.in","r",stdin);
    freopen("teleport.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a,b,x,y; cin>>a>>b>>x>>y;
    if(a>b) swap(a,b);
    if(x>y) swap(x,y);

    cout<<min({b-a,abs(a-x) + abs(b-y)})<<'\n';


}
