/*
    Author: HungForree
    Link: https://codeforces.com/problemset/problem/1149/C
*/

#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
const ll N = 200005;
const ll mod = 1e9+7;

struct Node
{
    ll sum, max_p, min_p, max_l, max_r, ans;
    void set_leaf(char c) {
        sum = (c == '(' ? 1 : -1);
        if(sum == 1) {
            max_p = 1; min_p = 0;
            max_l = 0; max_r = 1;
            ans = 1;
        } else {
            max_p = 0; min_p = -1;
            max_l = 2; max_r = 1;
            ans = 1;
        }
    }
};
string s;
Node tree[N<<2];
void pushup(ll curr)
{
    ll l = curr * 2;
    ll r = curr * 2 + 1;
    Node &res = tree[curr];
    Node &left = tree[l];
    Node &right = tree[r];

    res.sum = left.sum + right.sum;
    res.max_p = max(left.max_p, left.sum + right.max_p);
    res.min_p = min(left.min_p, left.sum + right.min_p);

    res.max_l = max({left.max_l,
                     right.max_l - left.sum,
                     left.max_p - 2 * left.sum - 2 * right.min_p});

    res.max_r = max({left.max_r,
                     right.max_r - left.sum,
                     -2 * left.min_p + left.sum + right.max_p});
    res.ans = max({left.ans,
                   right.ans,
                   left.max_l + left.sum + right.max_p,
                   left.max_p + right.max_r - left.sum});
}

void build(ll curr, ll l, ll r)
{
    if(l == r)
    {
        tree[curr].set_leaf(s[l]);
        return;
    }
    ll mid = (l + r) / 2;
    build(curr * 2, l, mid);
    build(curr * 2 + 1, mid + 1, r);
    pushup(curr);
}

void change(ll curr, ll l, ll r, ll pos)
{
    if(l == r)
    {
        tree[curr].set_leaf(s[l]);
        return;
    }
    ll mid = (l + r) / 2;
    if(pos <= mid) change(curr * 2, l, mid, pos);
    else change(curr * 2 + 1, mid + 1, r, pos);
    pushup(curr);
}

void solve()
{

    ll n, m;
    cin>>n>>m;

    ll len=2*n-2;
    cin>>s;

    if(len>0) build(1,0,len-1);

    cout<<(len>0?tree[1].ans:0)<<el;

    while(m--)
    {
        ll a,b;cin>>a>>b;
        a--; b--;

        if(s[a] != s[b]) {
            swap(s[a], s[b]);
            change(1,0,len-1,a);
            change(1,0,len-1,b);
        }
        cout<<(len>0?tree[1].ans:0)<<el;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;

    while(t--)
    {
        solve();
    }
}
