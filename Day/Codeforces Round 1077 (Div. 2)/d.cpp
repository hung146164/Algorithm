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

vector<ll> hh(ll a, ll b, ll uutien,ll first)
{
    ll ans1=0,ans2=0;
    ll cnt=0;
    for(ll i=31;i>=0; i--)
    {
        if(i>first)
        {
            if((a>>i)&1) ans1+=(1<<i);
            if((b>>i)&1) ans2+=(1<<i);
        }
        else if(i==first)
        {
            if(uutien==1)
            {
                ans1+=(1<<i);
            }
            else{
                ans2+=(1<<i);
            }
            cnt=uutien;
        }
        else if(cnt==1)
        {
            if( ((a>>first)&1) & ((b>>first)&1)) ans2+=(1<<i);
            else if((b>>i)&1) ans2+=(1<<i);
        }
        else
        {
            if( ((a>>first)&1) & ((b>>first)&1)) ans1+=(1<<i);
            else if((a>>i)&1) ans1+=(1<<i);
        }
    }
    return {abs(a-ans1)+abs(b-ans2),ans1,ans2};
}
void solve()
{
    ll a, b; cin>>a>>b;
//    vector<ll> a1,a2;
//    while(a)
//    {
//        a1.push_back((a%2));
//        a/=2;
//    }
//    while(b)
//    {
//        a2.push_back((b%2));
//        b/=2;
//    }
//    for(ll i=a1.size()-1; i>=0; i--) cout<<a1[i];
//    cout<<el;
//    for(ll i=a2.size()-1; i>=0; i--) cout<<a2[i];
//    cout<<el;
//    return;
    ll e=-1;
    for(ll i=31; i>=0 ;i--)
    {
        if(((a>>i)&1) && ((b>>i)&1))
        {
            e=i;
            break;
        }
    }
    if(e==-1)
    {
        cout<<a<<' '<<b<<el;
    }
    else{
        ll x=INT_MAX,y=-1,z=-1;
        for(ll i=31;i>=e; i--)
        {
            for(ll j=1; j<=2; j++)
            {
                vector<ll> curr=hh(a,b,j,i);
                if(curr[0]<x)
                {
                    x=curr[0];
                    y=curr[1];
                    z=curr[2];
                }
            }
        }
        cout<<y<<' '<<z<<el;
    }
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









