#include<bits/stdc++.h>
using namespace std;
string sol(int du,int a,int b, int c)
{
    if(du-a>=0)
    {
        du-=a;
    }
    else
    {
        return "Guiding Beat";
    }
    if(du-b>=0)
    {
        du-=b;
    }
    else return "Warning Beat";
    return "Resting Phase";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    {
        int a,b,c,d;cin>>a>>b>>c>>d;

        int sum=a+b+c;
        int du=d%sum;
        cout<<sol(du,a,b,c)<<endl;

    }
}
