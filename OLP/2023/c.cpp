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
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll p; cin>>p;
    string s; cin>>s;
    ll n=s.size();
    vector<ll> prefix(n+1);
    if(p==2)
    {
        for(ll i=0; i<n; i++)
        {
            ll val=0;
            if((s[i]-'0')%2==0)
            {
                val=i+1;
            }
            prefix[i+1]=prefix[i]+val;
        }
    }
    else if(p==5)
    {
        for(ll i=0; i< n; i++)
        {
            ll val=0;
            if(s[i]-'0'==5 || s[i]-'0'==0)
            {
                val=i+1;
            }
            prefix[i+1]=prefix[i]+val;
        }
    }
    else{

    }
    for(int i=0; i< prefix.size(); i++)
        cout<<prefix[i]<<' ';

    cout<<'\n';
    ll q; cin>>q;
    while(q--)
    {
        ll a, b; cin>>a>>b;
        cout<<prefix[b]-prefix[a-1]<<'\n';
    }
}

