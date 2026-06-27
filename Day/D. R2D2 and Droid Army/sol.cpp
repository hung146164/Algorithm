/*
    Author: HungForree
    Link: https://codeforces.com/problemset/problem/514/D
*/

#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
const ll N=5e5+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
using i128 = __int128;
constexpr i64 inf = 1E18;

class Seg
{
public:
    vector<ll> tree;
    vector<ll> nums;
    Seg(vector<ll>& num)
    {
        nums=num;
        tree.resize(num.size()*4);
        build(0,0,nums.size()-1);
    }
    void build(ll curr ,ll l, ll r)
    {
        if(l==r)
        {
            tree[curr]=nums[l];
            return;
        }
        ll m=l+(r-l)/2;
        build(curr*2+1,l,m);
        build(curr*2+2,m+1,r);
        tree[curr]=max(tree[curr*2+1],tree[curr*2+2]);
    }
    ll query(ll curr ,ll l, ll r, ll x, ll y)
    {
        if(r<x || l>y)
        {
            return 0;
        }
        if(x<=l && r<=y)
        {
            return tree[curr];
        }
        ll m=l+(r-l)/2;
        return max(query(curr*2+1,l,m,x,y),query(curr*2+2,m+1,r,x,y));
    }
};
void solve()
{
    ll n,m,k; cin>>n>>m>>k;
    vector<vector<ll>> nums(m);
    for(ll j=0; j< n; j++)
    {
        for(ll i=0; i< m; i++)
        {
            ll x; cin>>x;
            nums[i].push_back(x);
        }
    }
    vector<Seg> segs;
    for(ll i=0; i< m; i++)
    {
        Seg seg(nums[i]);
        segs.push_back(seg);
        //cout<<seg.query(0,0,n-1,0,n-1)<<el;
    }
    ll ans=0;
    vector<ll> re(m);
    for(ll l=0, r=0;r<n;)
    {
        ll val=0;
        vector<ll> c;
        for(ll i=0; i<m ;i++)
        {
            ll gt=segs[i].query(0,0,n-1,l,r);
            val+=gt;
            c.push_back(gt);
        }

        if(val>k)
        {
            l++;
        }
        else{
            if(ans<r-l+1)
            {
                ans=r-l+1;
                re=c;
            }
            r++;
        }
    }
    for(ll i=0; i< re.size(); i++)
    {
        cout<<re[i]<<' ';
    }

}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll t; t=1;
    while(t--)
    {
        solve();
    }
}









