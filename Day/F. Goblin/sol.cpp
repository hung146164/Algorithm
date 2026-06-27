/*
    Author: HungForree
    Link: https://codeforces.com/problemset/problem/2106/F
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

void solve()
{
    ll n; cin>>n;
    string s; cin>>s;
    if(s.size()==1 && s[0]=='0')
    {
        cout<<0<<el;
        return;
    }
    s=" "+s;
    ll len=0;
    ll curr=0;
    vector<ll> block;
    for(ll i=1; i<=n; i++)
    {
        if(s[i]-'0'!=curr)
        {
            block.push_back(len);
            len=1;
            curr=s[i]-'0';
        }
        else len++;
    }
    block.push_back(len);
    if(curr==1) block.push_back(0);
//    for(ll i=0; i< block.size(); i++)
//    {
//        cout<<block[i]<<' ';
//    }
//    cout<<el;
    ll blockleft=0;
    ll blockright=n-blockleft-block[0];
    ll up=block[0]*(block[0]-1)/2;
    ll down=block[0]*(block[0]-1)/2 + blockright*block[0];
    blockleft+=block[0];
    //ll ans=1;
    ll ans=max({up,down,1LL});
    for(ll i=2;i<block.size(); i+=2)
    {
        ans=max(ans,down+1);
        blockleft+=block[i-1];
        blockright=n-blockleft-block[i];
        up=block[i]*(block[i]-1)/2 + blockleft*block[i];
        ans=max(ans,up+1);
        if(block[i-1]==1)
        {
            ans=max(ans,up+down+1);
            down=block[i]*(block[i]-1)/2 + blockright*block[i];
        }
        else
        {
            down=block[i]*(block[i]-1)/2 + blockright*block[i];
        }

        blockleft+=block[i];
    }
    cout<<ans<<el;
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









