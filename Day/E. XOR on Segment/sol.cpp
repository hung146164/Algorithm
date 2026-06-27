/*
    Author: HungForree
    Link:
*/

#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
const ll N=1e5+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
using i128 = __int128;
constexpr i64 inf = 1E18;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
struct Node
{
    public:
    ll cnt0, cnt1,lazy;

    Node operator+(const Node& other) const{
        return {other.cnt0+cnt0,other.cnt1+cnt1,other.lazy+lazy};
    }
};
Node tree[20][N<<2];

ll nums[N];
void build(ll curr, ll l, ll r)
{
    if(l==r)
    {
        for(ll i=0; i< 20; i++)
        {
            if( (nums[l]>>i) &1) tree[i][curr]={0,1,0};
            else tree[i][curr]={1,0,0};
        }
        return;
    }
    ll m=l+(r-l)/2;
    build(curr*2+1,l,m);
    build(curr*2+2,m+1,r);
    for(ll i=0; i<20; i++)
    {
        tree[i][curr]=tree[i][curr*2+1]+tree[i][curr*2+2];
    }
}
void push(ll curr ,ll l, ll r,ll index)
{
    ll cnt=tree[index][curr].lazy%2==0?0:1;
    if(cnt==1)
    {
        swap(tree[index][curr].cnt0,tree[index][curr].cnt1);
    }
    if(l!=r)
    {
        tree[index][curr*2+1].lazy+=cnt;
        tree[index][curr*2+2].lazy+=cnt;

    }

    tree[index][curr].lazy=0;
}
void update(ll curr,ll l, ll r,ll x,ll y,ll index)
{
    push(curr, l, r,index);
    if(r<x || l>y) return;
    if(x<=l && r<=y)
    {
        tree[index][curr].lazy+=1;
        push(curr,l,r,index);
        return;
    }
    ll m=l+(r-l)/2;
    update(curr*2+1,l,m,x,y,index);
    update(curr*2+2,m+1,r,x,y,index);
    tree[index][curr]=tree[index][curr*2+1]+tree[index][curr*2+2];
}
ll query(ll curr ,ll l, ll r, ll x, ll y,ll index)
{
    push(curr,l,r,index);
     if(r<x || l>y) return 0;
     if(x<=l && r<=y)
    {
        return tree[index][curr].cnt1;
    }
    ll m=l+(r-l)/2;
    return query(curr*2+1,l,m,x,y,index)+query(curr*2+2,m+1,r,x,y,index);
}
ll pow2[20];
void process()
{
    pow2[0]=1;
    for(ll i=1; i<20; i++)
    {
        pow2[i]=pow2[i-1]*2;
    }
}
void solve()
{
    process();
    ll n; cin>>n;
    for(ll i=0; i< n; i++)
    {
        cin>>nums[i];
    }
    build(0,0,n-1);
    ll q; cin>>q;
    for(ll i=0; i< q; i++)
    {
        ll t ; cin>>t;
        if(t==1)
        {
            ll ans=0;
            ll a,b; cin>>a>>b;
            a--;b--;
            for(ll j=0; j<20 ;j++)
            {
                ans+=query(0,0,n-1,a,b,j)*pow2[j];
            }
            cout<<ans<<el;
        }
        else{
            ll a,b,c; cin>>a>>b>>c;
            a--;b--;
            for(ll j=0; j< 20; j++)
            {
                if( (c>>j) &1) update(0,0,n-1,a,b,j);
            }
        }
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









