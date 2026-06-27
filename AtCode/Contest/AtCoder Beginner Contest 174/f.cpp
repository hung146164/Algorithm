/*
    Author: HungForree
    Link: https://atcoder.jp/contests/abc174/tasks/abc174_f
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
const ll inf=1e18;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll base=rng() % 500 +300;
ll powll(ll a, ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a%mod;
        }
        a=a*a%mod;
        b/=2;
    }
    return ans;
}
class Seg
{
public:
    vector<int> tree,lazy,nums;
    Seg(vector<int> num)
    {
        int n=num.size();
        tree.resize(n*4);
        lazy.resize(n*4);
        nums=num;
        build(0,0,n-1);
    }
    void build(int curr ,int l, int r)
    {
        if(l==r)
        {
            tree[curr]=nums[l];
            return;
        }
        int m=l+(r-l)/2;
        build(curr*2+1,l,m);
        build(curr*2+2,m+1,r);
    }
    void updaterange(int curr,int l, int r, int x, int y, int val)
    {
        if(r<x || l>y) return;
        if(x<=l && r<=y)
        {
            lazy[curr]+=val;
            return;
        }
        int m=l+(r-l)/2;
        updaterange(curr*2+1,l,m,x,y,val);
        updaterange(curr*2+2,m+1,r,x,y,val);
    }
    void pop(int curr,int l, int r)
    {
        tree[curr]+=lazy[curr];
        if(l!=r)
        {
            lazy[curr*2+1]+=lazy[curr];
            lazy[curr*2+2]+=lazy[curr];
        }
        lazy[curr]=0;
    }
    int get(int curr ,int l, int r, int x)
    {
        pop(curr,l,r);
        if(l==r)
        {
            return tree[curr];
        }
        int m=l+(r-l)/2;
        if(x<=m)
        {
            return get(curr*2+1, l, m, x);
        }
        return get(curr*2+2,m+1,r,x);
    }
};
struct Node
{
    int l,  r,  id;
    bool operator<(const Node& other) const{
        if(r==other.r)
        {
            return l<other.l;
        }
        return r<other.r;
    }
};
void solve()
{
    int n,q ;cin>>n>>q;
    vector<int> nums(n);
    for(int i=0; i< n; i++)
    {
        cin>>nums[i];
    }
    vector<int> clone(n);
    Seg seg(clone);
    vector<Node> queries;
    for(int i=0; i< q; i++)
    {
        int a, b; cin>>a>>b;
        a--;b--;
        queries.push_back({a,b,i});
    }
    sort(queries.begin(),queries.end());
    unordered_map<int,int> dp;
    int curr=0;
    vector<int> ans(q);
    for(auto&[l,r,id]: queries)
    {
        while(curr<=r)
        {
            if(dp.find(nums[curr])!=dp.end())
            {
                seg.updaterange(0,0,n-1,0,dp[nums[curr]],-1);
            }
            seg.updaterange(0,0,n-1,0,curr,1);
            dp[nums[curr]]=curr;
            curr++;
        }
        ans[id]=seg.get(0,0,n-1,l);
    }
    for(auto& i: ans) cout<<i<<el;

}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int t; t=1;
    while(t--)
    {
        solve();
    }
}







