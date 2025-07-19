#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=5e5+1;
ll lazy[4*N];
ll money[N];
ll stock[N];

const int mod=1e9+7;
void lai(ll money)
{
    lazy[1]=(lazy[1]+money)%mod;
}
void progress(ll curr)
{
    lazy[curr*2]+=lazy[curr];
    lazy[curr*2]%=mod;
    lazy[curr*2+1]+=lazy[curr];
    lazy[curr*2+1]%=mod;
    lazy[curr]=0;
}
void updatelazy(ll curr,ll l,ll r,ll p)
{
    if(l==r)
    {
        money[p] = (money[p] + (lazy[curr] % mod) * (stock[p] % mod) % mod) % mod;

        money[p]%=mod;
        lazy[curr]=0;
        return;
    }
    progress(curr);
    ll m=l+(r-l)/2;
    if(p<=m)
    {
        updatelazy(curr*2,l,m,p);
    }
    else{
        updatelazy(curr*2+1,m+1,r,p);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,q;cin>>n>>q;
    while(q--)
    {
        ll k;cin>>k;
        if(k==1)
        {
          ll p,x;cin>>p>>x;
          updatelazy(1,1,n,p);
          stock[p]=((stock[p]+x)%mod+mod)%mod;
        }
        else if(k==2)
        {
            ll v;cin>>v;
            lai(v);
        }
        else{
            ll p;cin>>p;
            updatelazy(1,1,n,p);
            cout<<money[p]<<'\n';
            money[p]=0;
        }
    }
}
