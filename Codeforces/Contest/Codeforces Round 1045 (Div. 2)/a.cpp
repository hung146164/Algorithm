#include<bits/stdc++.h>
using namespace std;
int sol(int n,int a,int b)
{
    if(n%2==0)
    {
        if((a%2==1 && b%2==0 && b<a) || (b%2==1)) return false;
    }
    else{
        if((a%2==0&& b%2==1 && b<a) || (b%2==0)) return false;
    }
    return true;
}
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,a,b;cin>>n>>a>>b;
        cout<<(sol(n,a,b)?"YES":"NO")<<'\n';
    }
}
