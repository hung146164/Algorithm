/*
    Author: HungForree
    Link: https://codeforces.com/problemset/problem/1366/D
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
int mnt[N];
void sang()
{
    for(int i=2; i<N; i++)
    {
        if(mnt[i]==0)
        {
            for(int j=i;j<N;j+=i)
            {
                if(mnt[j]==0) mnt[j]=i;
            }
        }
    }
}
int gcd(int a, int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
void solve()
{
    sang();
//    for(int i=0; i<10; i++)
//    {
//        cout<<mnt[i]<<' ';
//    }
    int n; cin>>n;
    vector<int> a, b;
    vector<int> nums(n);
    vector<vector<int>> dp(n);
    for(int i=0; i< n; i++)
    {
        cin>>nums[i];
        int clone=nums[i];
        while(clone!=1)
        {
            dp[i].push_back(mnt[clone]);
            clone/=mnt[clone];
        }
        dp[i].push_back(nums[i]);
    }
    for(int i=0; i< n; i++)
    {
        bool have=false;
        for(int j=0; j< dp[i].size(); j++)
        {
            for(int k=j+1;k<dp[i].size(); k++)
            {
                if(gcd(dp[i][j]+dp[i][k],nums[i])==1)
                {
                    a.push_back(dp[i][j]);
                    b.push_back(dp[i][k]);
                    have=true;
                    break;
                }
            }
            if(have) break;
        }
        if(!have)
        {
            a.push_back(-1);
            b.push_back(-1);
        }
    }
    for(int i=0; i< n; i++)
    {
        cout<<a[i]<<' ';
    }
    cout<<el;
    for(int i=0; i< n;i++)
    {
        cout<<b[i]<<' ';
    }
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









