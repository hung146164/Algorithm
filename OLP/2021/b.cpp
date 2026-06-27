#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll N=1e5+1;

class Seg
{
public:
    vector<ll> tree;
    vector<pair<ll,ll>> treemin;
    Seg(vector<ll>& nums)
    {
        tree.resize(nums.size()*4);
        treemin.resize(nums.size()*4,{INT_MAX,-1});
        build(0,0,nums.size()-1,nums);
    }
    void build(ll curr, ll l,ll r,vector<ll>& nums)
    {
        if(l==r)
        {
            tree[curr]=nums[l];
            treemin[curr]={nums[l],l};
            return;
        }

        ll m=l+(r-l)/2;
        build(curr*2+1,l,m,nums);
        build(curr*2+2,m+1,r,nums);
        tree[curr]=tree[curr*2+1]+tree[curr*2+2];

        if(treemin[curr*2+1].first >treemin[curr*2+2].first)
        {
            treemin[curr]=treemin[curr*2+2];
        }
        else treemin[curr]=treemin[curr*2+1];


    }
    void update(ll curr, ll l,ll r, ll x,ll val)
    {
        if(l==r)
        {
            tree[curr]=val;
            treemin[curr]={val,l};
            return;
        }
        ll m=l+(r-l)/2;
        if(x<=m)
        {
            update(curr*2+1,l,m,x,val);
        }
        else update(curr*2+2,m+1,r,x,val);
        tree[curr]=tree[curr*2+1]+tree[curr*2+2];
        if(treemin[curr*2+1].first >treemin[curr*2+2].first)
        {
            treemin[curr]=treemin[curr*2+2];
        }
        else treemin[curr]=treemin[curr*2+1];
    }
    ll querysum(ll curr,ll l,ll r,ll x, ll y)
    {
        if(r<x || l>y) return 0;
        if(x<=l && r<=y) return tree[curr];
        ll m=l+(r-l)/2;
        return querysum(curr*2+1,l,m,x,y)+querysum(curr*2+2,m+1,r,x,y);
    }
    pair<ll,ll> querymin(ll curr ,ll l,ll r, ll x,ll y)
    {
        if(r<x || l>y) return {INT_MAX,-1};
        if(x<=l && r<=y) return treemin[curr];

        ll m=l+(r-l)/2;
        pair<ll,ll> left=querymin(curr*2+1,l,m,x,y);
        pair<ll,ll> right=querymin(curr*2+2,m+1,r,x,y);

        if(left.first>right.first)
        {
            return right;
        }
        else return left;
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
    Seg seg(nums);
    ll diff=0;
    while(q--)
    {
        ll k; cin>>k;

        if(k==1)
        {
            ll d; cin>>d;
            diff+=d;
            diff%=n;
        }
        else if(k==2)
        {
            ll s,t,p;cin>>s>>t>>p;
            s--;
            t--;
            s=((s-diff)%n+n)%n;
            t=((t-diff)%n+n)%n;
            if(s<=t)
            {
                pair<ll,ll> m=seg.querymin(0,0,n-1,s,t);
                seg.update(0,0,n-1,m.second,p);
            }
            else{
                pair<ll,ll> left=seg.querymin(0,0,n-1,0,t);
                pair<ll,ll> right=seg.querymin(0,0,n-1,s,n-1);

                if(left.first<right.first)
                {
                    seg.update(0,0,n-1,left.second,p);
                }
                else{
                    seg.update(0,0,n-1,right.second,p);
                }
            }
        }
        else
        {
            ll s,t; cin>>s>>t;
            s--;
            t--;
            s=((s-diff)%n+n)%n;
            t=((t-diff)%n+n)%n;
            //cout<<s<<' '<<t<<'\n';
            if(t>=s)
            {
                cout<< seg.querysum(0,0,n-1,s,t)<<endl;
            }
            else{
                cout<< seg.querysum(0,0,n-1,s,n-1)+seg.querysum(0,0,n-1,0,t)<<endl;
            }
        }
    }
}


