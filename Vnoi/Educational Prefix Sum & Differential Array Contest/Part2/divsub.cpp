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

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,p; cin>>n>>p;
    unordered_map<ll,ll> m;
    m.reserve(2*100000);
    string s; cin>>s;
    m[0]++;
    ll curr=0;
    ll ans=0;
    for(ll i=0; i< n;i++)
    {
        curr*=10;
        curr+=s[i]-'0';
        curr%=p;
        ans+=m[curr];
        m[curr]++;
    }
    cout<<ans<<'\n';

}


