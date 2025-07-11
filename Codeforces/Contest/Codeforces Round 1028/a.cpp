#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int c1=min(a,c);
        int c2=min(b,d);
        if(c1>=c2)
        {
            cout<<"Gellyfish"<<'\n';
        }
        else cout<<"Flower"<<'\n';

    }
}
