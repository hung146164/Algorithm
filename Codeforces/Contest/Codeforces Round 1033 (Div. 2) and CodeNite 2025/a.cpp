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
        int a,b,c,d,e,f;
        cin>>a>>b>>c>>d>>e>>f;
        if((a==c+e && a==b+d)||
            (b==d+f && b==a+c) ||
           (a==c && c==e && b+d+f==a) ||
          (b==d && d==f && a+c+e==b)) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
}
