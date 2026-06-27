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
const ll N=3e5+5;
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

ll nums[N];

void solve()
{
    ll n; cin >> n;

    for(ll i=1;i<= n;i++)
    {
        cin>>nums[i];
    }
    vector<ll> next_index(n+2,n+1);
    ll last = n + 1;
    for(ll i = n; i >= 2; i--) {
        if(nums[i] > nums[i-1]+1) {
            last = i;
        }
        next_index[i-1] = last;
    }
    next_index[n] = n + 1;

    vector<ll> next_val(n+2,n+1);

    stack<ll> st;

    for(ll i = n; i >= 1; i--) {
        while(!st.empty() && nums[st.top()] > nums[i]) {
            st.pop();
        }
        if(!st.empty()) {
            next_val[i] = st.top();
        }
        st.push(i);
    }

    vector<ll> depth(n + 2,0);
    ll ans = 0;

    for(ll i = n; i >= 1; i--) {
        ll p= min(next_index[i], next_val[i]);
        depth[i]= depth[p]+(n-i+1);
        ans+= depth[i];
    }

    cout<<ans<<el;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll t; cin >> t;
    while(t--)
    {
        solve();
    }
}
