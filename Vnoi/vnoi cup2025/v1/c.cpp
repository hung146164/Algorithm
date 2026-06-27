#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll N=1e5+1;

class Seg
{
public:
    vector<ll> tree;
    vector<ll> lazy;
    vector<ll> lai;
    Seg(ll n)
    {
        tree.resize(n*4);
        lazy.resize(n*4);
        lai.resize(n*4);
    }
    void pop(ll curr,ll l, ll r)
    {
        if(l==r)
        {

            lai[curr]= (lai[curr] + tree[curr]*lazy[curr]%mod)%mod;
            lazy[curr]=0;
            return;
        }
        lazy[curr*2+1]=(lazy[curr*2+1]+lazy[curr])%mod;
        lazy[curr*2+2]=(lazy[curr*2+2]+lazy[curr])%mod;
        lazy[curr]=0;
    }
    void add(ll curr,ll l,ll r,ll p,ll x)
    {
        pop(curr,l,r);
        if(l==r)
        {
            tree[curr]=((tree[curr]+x)%mod+mod)%mod;
            return;
        }
        ll m=l+(r-l)/2;
        if(p<=m)
        {
            add(curr*2+1,l,m,p,x);
        }
        else{
            add(curr*2+2,m+1,r,p,x);
        }
    }
    void loi(ll x)
    {
        lazy[0]=(lazy[0]+x)%mod;
    }
    ll rut(ll curr,ll l,ll r,ll p)
    {
        pop(curr,l,r);
        if(l==r)
        {
            ll ans = lai[curr];
            lai[curr]=0;
            //DB();
            return ans;
        }
        ll m=l+(r-l)/2;
        if(p<=m)
        {
            return rut(curr*2+1,l,m,p);
        }
        else{
            return rut(curr*2+2,m+1,r,p);
        }
    }
    void DB()
    {
        for(ll i=0; i< tree.size() ;i++)
        {
            cout<<tree[i]<<' ';
        }
        cout<<'\n';
    }


};
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,q;cin>>n>>q;
    Seg seg(n);
    while(q--)
    {
        ll k; cin>>k;
        if(k==1)
        {
            ll p,x; cin>>p>>x;
            p--;
            seg.add(0,0,n-1,p,x);
        }
        else if(k==2)
        {
            ll v; cin>>v;
            seg.loi(v);
        }
        else{
            ll p; cin>>p;
            p--;
            cout<<seg.rut(0,0,n-1,p)<<'\n';
        }
    }
}


