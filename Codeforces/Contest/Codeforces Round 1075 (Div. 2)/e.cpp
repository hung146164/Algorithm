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
    ll n; cin>>n;
    string s; cin>>s;
    ll c0=0,c1=0;
    for(ll i=0; i<s.size(); i++)
    {
        (s[i]=='0')?c0++: c1++;
    }

    if(c1==0)
    {
        cout <<-1 << el;
        return;
    }

    if(c1>=c0) {
        cout<< (n==1?0:n)<<el;
        return;
    }

    ll need = c0 - c1;
    vector<ll> pos;
    int i=0;
    while(i<n)
    {
        ll j=i;
        while(j<n-1 && !(s[j]=='1' && s[j+1]=='1')) j++;

        ll l= i, r= j;
        while(l<=r && s[l]=='1') l++;
        while(r>=l && s[r]=='1') r--;

        if(l<=r)
        {
            ll z=0,o=0;
            for(ll ii=l; ii<=r;ii++) (s[ii]=='0')?z++:o++;
            if(z-o-1>0) pos.push_back(z-o-1);
        }
        i=j+1;
    }

    sort(pos.begin(),pos.end(),greater<ll>());
    ll them = 0;
    for(ll i=0; i< pos.size(); i++)
    {
        if(need<=0) break;
        need-= pos[i];
        them++;
    }
    if(need>0) them+=need;

    cout<<n+them<<el;
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








