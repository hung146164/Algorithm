#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll N=1e5+1;


bool check(ll a, ll b)
{
    while(a)
    {
        if(a%10==b) return true;
        a/=10;
    }
    return false;

}
class Seg{
public:
    vector<ll> tree;
    Seg(vector<ll>& nums,ll k)
    {
        tree.resize(nums.size()*4);
        build(nums,0,0,nums.size()-1,k);
    }

    void build(vector<ll>& nums ,ll curr ,ll l,ll r,ll k)
    {
        if(l==r)
        {
            if((l+1)%k==0 || check(l+1,k))
            {
                tree[curr]=nums[l];
            }
            return;
        }
        ll m=l+(r-l)/2;
        build(nums,curr*2+1,l,m,k);
        build(nums,curr*2+2,m+1,r,k);
        tree[curr]=tree[curr*2+1]+tree[curr*2+2];
    }
    ll query(ll curr ,ll l, ll r, ll x, ll y)
    {
        if(r<x || l> y) return 0;
        if(x<=l && r<=y) return tree[curr];
        ll m=l+(r-l)/2;
        return query(curr*2+1,l,m,x,y)+query(curr*2+2,m+1,r,x,y);
    }
    void update(ll curr,ll l,ll r,ll x,ll val)
    {
        if(l==r)
        {
            tree[curr]=val;
            return;
        }
        ll m=l+(r-l)/2;
        if(x<=m) update(curr*2+1,l,m,x,val);
        else update(curr*2+2,m+1,r,x,val);
        tree[curr]=tree[curr*2+1]+tree[curr*2+2];
    }

};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,q; cin>>n>>q;
    vector<ll> nums;
    for(ll i=0; i< n; i++)
    {
        ll x; cin>>x;
        nums.push_back(x);
    }
    vector<Seg> segs;
    for(ll i=1;i<=9 ;i++)
    {
        Seg seg(nums,i);
//        cout<<seg.query(0,0,n-1,0,n-1)<<'\n';
        segs.push_back(seg);
    }

    while(q--)
    {
        ll t;cin>>t;
        if(t==1)
        {
            ll pos,val;
            cin>>pos>>val;
            for(ll i=1; i<=9; i++)
            {
                if(pos%i==0 || check(pos,i))
                {
                    //cout<<"hh"<<i<<'\n';
                    segs[i-1].update(0,0,n-1,pos-1,val);
                }
            }
        }
        else{
            ll ans=0;
            ll l,r,k; cin>>l>>r>>k;

            ans+=segs[0].query(0,0,n-1,l-1,r-1);
            ans+=segs[k-1].query(0,0,n-1,l-1,r-1);

            cout<<ans<<'\n';
        }
    }
//    for(ll i=1; i<=9;i++)
//    {
//        cout<<segs[i-1].query(0,0,n-1,0,n-1)<<'\n';
//    }

}


