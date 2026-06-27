/*
    Author: HungForree
    Link: https://codeforces.com/problemset/problem/380/C
*/

#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
const ll N=1e6+5;
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
    int cnt;
    int left;
    int right;
    Node()
    {
        cnt=0;
        left=0;
        right=0;
    }
    Node(int cnt_,int left_,int right_)
    {
        cnt=cnt_;
        left=left_;
        right=right_;
    }
};
//cnt,(,)
Node tree[N*4];
int nums[N];
Node merge(Node&left, Node& right)
{
    int add=min(left.left,right.right);
    return Node(left.cnt+right.cnt+add,left.left+right.left-add,left.right+right.right-add);
}
void build(int curr,int l, int r)
{
    if(l==r)
    {
        if(nums[l]==1) tree[curr]=Node(0,1,0);
        else tree[curr]=Node(0,0,1);
        return;
    }
    int m=l+(r-l)/2;
    build(curr*2+1,l,m);
    build(curr*2+2,m+1,r);

    tree[curr]= merge(tree[curr*2+1],tree[curr*2+2]);
}
Node query(int curr ,int l,int r,int x,int y)
{
    if(r<x || l>y) return {0,0,0};
    if(x<=l && r<=y) return tree[curr];
    int m=l+(r-l)/2;
    Node left=query(curr*2+1,l,m,x,y);
    Node right=query(curr*2+2,m+1,r,x,y);
    return merge(left,right);

}
void solve()
{
    string s; cin>>s;

    for(int i=0; i< s.size(); i++)
    {
        if(s[i]=='(')
        {
            nums[i]=1;
        }
        else
        {
            nums[i]=2;
        }
    }
    build(0,0,s.size()-1);
    int q; cin>>q;
    while(q--)
    {
        int a, b; cin>>a>>b;
        a--;
        b--;
        cout<<query(0,0,s.size()-1,a,b).cnt*2<<el;
    }
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









