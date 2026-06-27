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
const ll N=1e6+1;
const ll mod=1e6+1;
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

bool ok[N];
vector<ll> sang()
{
    vector<ll> ans;
    for(ll i=2; i< N; i++)
    {
        if(!ok[i])
        {
            ans.push_back(i*i);
            for(ll j=i*i; j<N; j+=i)
            {
                ok[j]=true;
            }
        }
    }
    return ans;
}
void solve()
{
    ll n; cin>>n;
    vector<ll> c=sang();
    for(ll i=0; i< n; i++)
    {
        ll x; cin>>x;
        auto it=lower_bound(c.begin(),c.end(),x);
        if(it!=c.end() && *it==x)
        {
            cout<<"YES"<<el;
        }
        else
        {
            cout<<"NO"<<el;
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









