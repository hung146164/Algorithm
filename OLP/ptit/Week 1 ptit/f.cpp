#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gdc(ll a, ll b)
{
    if(b==0) return a;
    return gdc(b,a%b);
}
int sol()
{
    string a;ll b; cin>>b>>a;
    ll n=0;
    for(int i=0 ;i<a.size(); i++)
    {
        n*=10;
        n+=a[i]-'0';
        if(n>=b)
        {
            n%=b;
        }
    }
    return gdc(b,n);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--)
    {
        cout<<sol()<<'\n';
    }
}


