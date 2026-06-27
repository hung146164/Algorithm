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

vector<ll> sang (vector<ll>& nums, ll n)
{

    vector<ll> ans(n+1,inf);


    bool has_one = false;
    for(ll x : nums) if(x == 1) has_one = true;
    if(has_one) ans[1] = 1;


    for(ll x : nums)
    {
        if(x <= 1) continue;


        ans[x] = min(ans[x], 1LL);


        for(ll i=1;i*x<= n;i++)
        {
            if(ans[i]!=1e9)
            {
                ans[i*x]=min(ans[i * x],ans[i]+1);
            }
        }
    }
    return ans;
}

void solve()
{
    ll n; cin >> n;
    vector<ll> nums(n);
    for(ll i = 0; i < n; i++)
    {
        cin>>nums[i];
    }

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    vector<ll> ans = sang(nums, n);

    for(ll i=1;i<=n;i++)
    {
        cout <<(ans[i]>=1e9?-1:ans[i])<<' ';
    }
    cout << el;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
