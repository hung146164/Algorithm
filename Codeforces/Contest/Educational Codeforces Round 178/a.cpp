#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
     while (t--)
    {
        int a,b,c;cin>>a>>b>>c;
        if((c-abs(a-b)-max(a,b))%3==0 && (c-abs(a-b))>=max(a,b)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
