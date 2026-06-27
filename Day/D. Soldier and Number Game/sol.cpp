/*
    Author: HungForree
    Link: https://codeforces.com/contest/546/problem/D
*/

#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
const ll N=5e6+5;
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
ll mnt[N];
ll prefix[N];
void sang()
{
    mnt[1]=1;
    for(ll i=2; i<N; i++)
    {
        if(mnt[i]==0)
        {
            for(ll j=i;j<N; j+=i)
            {
                if(mnt[j]==0 || mnt[j]>i)
                {
                    mnt[j]=i;
                }
            }
        }
    }
}
void solve()
{
    ll a, b; cin>>a>>b;
//    ll ans=0;
//    for(int i=2;i<=10; i++)
//    {
//        cout<<mnt[i]<<' ';
//    }
//    cout<<el;
    cout<<prefix[a]-prefix[b]<<el;

}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    sang();

    for(ll i=2;i<N; i++)
    {
        int ans=0;
        ll clone=i;
        while(clone!=1)
        {
            clone/=mnt[clone];
            ans++;
        }
        prefix[i]=ans+prefix[i-1];
    }
//    for(int i=2;i<=10; i++)
//    {
//        cout<<prefix[i]<<' ';
//    }
//    cout<<el;
    ll t; cin>>t;
    while(t--)
    {
        solve();
    }
}









