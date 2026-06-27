#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll N=1e5+1;

ll maxll(ll a,ll b)
{
    if(a>b) return a;
    return b;
}
ll minll(ll a,ll b)
{
    if(a>b) return b;
    return a;
}
ll gdc(ll a, ll b)
{
    if(b==0) return a;
    return gdc(b,a%b);
}

namespace sub1
{
    bool CheckSub1()
    {
        return true;
    }
    void sol()
    {

    }
}
namespace sub2
{
    bool CheckSub2()
    {
        return true;
    }
    void sol()
    {

    }
}
namespace sub3
{
    bool CheckSub3()
    {
        return true;
    }
    void sol()
    {

    }
}
ll sol(string& s1, string &s2)
{
    ll ans=1;
    for(ll i=0; i< s1.size(); i++)
    {
        if(s1[i]==s2[i] && s2[i]=='O') return 0;
        else if(s1[i]==s2[i] && s2[i]=='X') ans=ans*2%mod;
    }
    return ans;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin>>t;
    while(t--)
    {

    string s; cin>>s;
    string s2; cin>>s2;
    cout<<sol(s,s2)<<'\n';
    }
}


