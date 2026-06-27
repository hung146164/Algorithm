#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=1e5+1;

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

class Seg
{
    vector<int> tree;
    vector<int> lazy;
    Seg(int n)
    {
        tree.resize(n*4);
        lazy.resize(n*4);
        build(0,0,n-1);
    }
    void build(int curr,int l,int r)
    {
        if(l==r)
        {
            tree[curr]=1;
            return;
        }
        int m=l+(r-l)/2;
        build(curr*2+1,l,m);
        build(curr*2+2,m+1,r);
        tree[curr]=gdc(tree[curr*2+1],tree[curr*2+2]);
    }
    void update(int curr,int l,int r,int x,int y,int val)
    {
        if(r<x || y<l) return;
        if(x<=l && r<=y)
        {
            lazy[curr]+=val;
            return;
        }
        int m=l+(r-l)/2;
        update(curr*2+1,l,m,x,y,val);
        update(curr*2+2,m+1,r,x,y,val);
    }

};
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q; cin>>n>>q;
    Seg(n);

}


