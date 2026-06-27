/*
    Author: HungForree
    Link: https://codeforces.com/contest/1649/problem/D
*/
/*
    ky thuat kiem tra ton tai bang prefix
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
ll gcd(ll a,ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
ll lcm(ll a, ll b)
{
    return a*b/gcd(a,b);
}
void solve()
{
    ll n, c; cin>>n>>c;
    vector<ll> nums(n);
    vector<ll> prefix(c+1);
    for(ll i=0; i< n; i++)
    {
        cin>> nums[i];
        prefix[nums[i]]=1;
    }
    for(ll i=1; i<=c; i++)
    {
        prefix[i]+=prefix[i-1];
    }
//    for(int i=0; i< prefix.size(); i++)
//    {
//        cout<<prefix[i]<<' ';
//    }
//    cout<<el;
    sort(nums.begin(), nums.end());
    vector<bool> cnt(c+1);
    for(ll i=0; i<n; i++)
    {
        cnt[nums[i]]=true;
    }

    for(ll i=1;i<=c;i++)
    {
        if(!cnt[i])
        {
            //cout<<i<<' ';
            for(ll j=0; j< nums.size(); j++)
            {
                if(prefix[min(c,nums[j]*(i+1)-1)]-prefix[min(c,nums[j]*i-1)] !=0){
                    //cout<<i<<' '<<nums[j]<<el;
                    cout<<"NO"<<el;
                    return;
                }
            }
        }
    }
    cout<<"YES"<<el;
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









