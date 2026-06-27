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
const ll N=1e7+5;
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
    vector<ll> nums(n);
    vector<ll> check(N);
    for(ll i=0; i< n; i++)
    {
        ll x; cin>>x;
        check[x]++;
        nums[i]=x;
    }
    ll ans=LLONG_MAX;
    vector<ll> hehe(2,-1);
    for(ll i=1; i<N; i++)
    {
        ll pre=-1;
        for(ll j=i;j<N;j+=i)
        {
            if(check[j]==1)
            {
                if(pre==-1)
                {
                    pre=j;
                }
                else
                {
                    if(pre/i*j<ans)
                    {
                        ans=pre/i *j;
                        hehe[0]=pre;
                        hehe[1]=j;
                    }
                    break;
                }
            }
            else if(check[j]>1)
            {
                if(pre==-1)
                {
                    if(j/i*j<ans)
                    {
                        ans=j/i*j;
                        hehe[0]=j;
                        hehe[1]=j;
                    }

                }
                else
                {
                    if(pre/i*j<ans)
                    {
                        ans=pre/i *j;
                        hehe[0]=pre;
                        hehe[1]=j;
                    }
                }
                break;
            }
        }
    }
    for(ll i=0; i< n; i++)
    {
        if(nums[i]==hehe[0])
        {
            cout<<i+1<<' ';
            hehe[0]=-1;
            continue;
        }
        if(nums[i]==hehe[1])
        {
            cout<<i+1<<' ';
            hehe[1]=-1;
        }
    }
    cout<<el;
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









