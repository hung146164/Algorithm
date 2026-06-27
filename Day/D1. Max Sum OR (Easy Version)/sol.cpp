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

void solve()
{
    ll l, r; cin>>l>>r;
    vector<int> bitmax(r-l+1);
    vector<int> pos(r-l+1);
    ll ans=0;
    for(ll  i=r;i>=l; i--)
    {
        int val=r;
        for(ll  j=30;j>=0; j--)
        {
            if(val>=(1<<j))
            {
                int k=val-(1<<j);
                int candidate_val= i-2*k-1;
                if(candidate_val>=l && bitmax[candidate_val-l]<j)
                {
                    bitmax[candidate_val-l]=j;
                    pos[candidate_val-l]=i;
                }
                val-=1<<j;
            }
        }
    }
    for(int i=0; i<pos.size(); i++)
    {
        cout<<pos[i]<<' ';
        ans+=(i+l)|pos[i];
    }
    cout<<el;
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









