/*
    Author: HungForree
    Link: https://codeforces.com/problemset/problem/1400/D
*/

#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
const ll N=3005;
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

int nums[N];
int prefix[N][N];
int suffix[N][N];
void solve()
{
    int n; cin>>n;
    vector<int> clone(n);
    for(int i=1; i<= n; i++)
    {
        cin>> nums[i];
        clone[i-1]=nums[i];
    }
    sort(clone.begin(), clone.end());
    clone.erase(unique(clone.begin(), clone.end()), clone.end());
    int len=0;
    for(int i=1; i<=n; i++)
    {
        nums[i]=lower_bound(clone.begin(),clone.end(),nums[i])-clone.begin();
        len=max(len,nums[i]);
    }

    for(int i=1; i<= n;i++)
    {
        for(int j=0;j<=len; j++)
        {
            prefix[i][j]=prefix[i-1][j]+(j==nums[i]?1:0);

        }

    }
    for(int i=n; i>=1;i--)
    {
        for(int j=0;j<=len; j++)
        {
            suffix[i][j]=suffix[i+1][j]+(j==nums[i]?1:0);
        }
    }
    ll ans=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<= n; j++)
        {
            ans=ans+prefix[i-1][nums[j]]*suffix[j+1][nums[i]];
        }
    }
    cout<<ans<<el;
    for(int i=1;i<=n; i++)
    {
        for(int j=0;j<=len;j++)
        {
            prefix[i][j]=suffix[i][j]=0;
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int t; cin>>t;
    while(t--)
    {
        solve();
    }
}










