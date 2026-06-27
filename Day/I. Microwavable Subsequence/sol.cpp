/*
    Author: HungForree
    Link: https://codeforces.com/contest/2045/problem/I
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

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
bool cmp(const vector<int>& a,const vector<int>& b)
{
    return a[1]<b[1];
}

int tree[N*4];
int lazy[N*4];
void push(int curr, int l, int r)
{
    if (lazy[curr] != 0)
    {
        tree[curr] += lazy[curr] * (r - l + 1);
        if (l != r)   // tránh đẩy xuống lá vô ích
        {
            lazy[curr * 2 + 1] += lazy[curr];
            lazy[curr * 2 + 2] += lazy[curr];
        }
        lazy[curr] = 0;
    }
}
void update(int curr,int l,int r,int x,int y,int val)
{
    if(r<x || l>y) return;
    if(x<=l && r<=y)
    {
        lazy[curr]+=val;
        return;
    }
    int m=l+(r-l)/2;
    update(curr*2+1,l,m,x,y,val);
    update(curr*2+2,m+1,r,x,y,val);
}
int qq(int curr,int l,int r, int x)
{
    push(curr,l,r);
    if(l==r)
    {
        return tree[curr];
    }
    int m=l+(r-l)/2;
    if(x<=m) return qq(curr*2+1, l,m,x);
    return qq(curr*2+2,m+1,r,x);
}

void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<ll> cnt(m+1);
    vector<int> nums(n);
    for(ll i=0; i< n; i++)
    {
        ll x;
        cin>>x;
        cnt[x]++;
        nums[i]=x;
    }
    ll z=0;
    ll o=0;
    for(ll i=1; i<=m; i++)
    {
        if(cnt[i]==0)
        {
            z++;
        }
        else
        {
            o++;
        }
    }
    ll ans=z*o;
    //cout<<o<<el;
    for(ll i=1; i<=m; i++)
    {
        if(cnt[i]>0)
        {
            ans+=cnt[i]*(o-1);
        }
        //cout<<cnt[i]<<' ';
    }
    vector<vector<int>> pos(m+1);
    for(int i=0; i<n; i++)
    {
//        if(i==n-1)
//        {
//            pos[nums[i]].push_back(i);
//            break;
//        }
//        if(i<n && nums[i]==nums[i+1])
//        {
//            pos[nums[i]].push_back(i);
//            while(i+1<n && nums[i]==nums[i+1])
//            {
//                i++;
//            }
//        }
//        else
//        {
//            pos[nums[i]].push_back(i);
//        }
        pos[nums[i]].push_back(i);
    }

    vector<vector<int>> query;
//    for(int i=1; i<=m ; i++)
//    {
//        for(int j=0; j< pos[i].size(); j++)
//        {
//            cout<<pos[i][j]<<' ';
//        }
//        cout<<el;
//    }
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j< pos[i].size(); j++)
        {
            query.push_back({pos[i][j-1],pos[i][j]});
        }
    }
    sort(query.begin(),query.end(),cmp);
    unordered_map<int,int> dp;
    dp.reserve(n * 2);
    int l=0;
    for(int i=0; i<n; i++)
    {
        if(l==query.size()) break;
        while(l<query.size() && query[l][1]<i)
        {
            l++;
        }
        if(dp.find(nums[i])!=dp.end())
        {
            update(0,0,n-1,0,dp[nums[i]],-1);
        }
        dp[nums[i]]=i;

        update(0,0,n-1,0,i,1);
        while(l<query.size() && query[l][1]==i)
        {
            int val = qq(0,0,n-1,query[l][0]);
            //cout<<query[l][0]<<' '<<query[l][1]<<' '<<val<<el;
            ans-=o-val;
            l++;
        }
    }
    cout<<ans<<el;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll t;
    t=1;
    while(t--)
    {
        solve();
    }
}









