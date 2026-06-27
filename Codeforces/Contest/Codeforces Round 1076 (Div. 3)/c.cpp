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
const ll N=5e5+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
using i128 = __int128;
constexpr i64 inf = 1E18;

void solve()
{
    ll n,q; cin>>n>>q;
    vector<ll> a(n),b(n);
    for(ll i=0;i < n; i++)
    {
        cin>>a[i];
    }
    for(ll i=0; i< n; i++)
    {
        cin>>b[i];
    }
    vector<ll> dp1(n);
    ll curr=0;
    for(ll i=n-1; i>=0; i--)
    {
        curr=max({curr,a[i],b[i]});
        dp1[i]=curr;
    }
    vector<ll> p ;
    ll sum=0;
    for(ll i=0; i<n; i++)
    {
        p.push_back(sum+dp1[i]);
        sum+=dp1[i];
    }

    for(ll i=0; i< q; i++)
    {
        ll a, b; cin>>a>>b;
        a--;b--;
        ll v2=p[b];
        ll v1=a==0?0:p[a-1];
        cout<<v2-v1<<' ';
    }
    cout<<el;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll t; cin>>t;
    while(t--)
    {
        solve();
    }
}









