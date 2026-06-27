/*
    Author: HungForree
    Link: https://codeforces.com/contest/448/problem/C
*/

#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
const ll N=5e3+5;
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

int sol(int l, int r)
{
    if(l==r)
    {
        return 1;
    }
    if(r<l) return 0;
    int ans=r-l+1;
    int minn=nums[l];
    for(int i=l;i<=r; i++)
    {
        minn=min(nums[i],minn);
    }

    int k=0;
    int c=l;
    for(int i=l; i<=r; i++)
    {
        nums[i]-=minn;
        if(nums[i]==0)
        {
            k+=sol(c,i-1);
            c=i+1;
        }
    }
    k+=sol(c,r);
    ans=min(ans,k+minn);
    return ans;
    //2 2 1 2 1

}
void solve()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>nums[i];
    }
    cout<<sol(1,n)<<el;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int t; t=1;
    while(t--)
    {
        solve();
    }
}










