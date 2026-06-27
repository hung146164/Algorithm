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
int nums[N];
void solve()
{
    int n; cin>>n;
    int a=0,b=0;
    vector<int> a(n),b(n);
    for(int i=0; i< n; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i< n; i++)
    {
        cin>>b[i];
    }
    int cnta=0,cntb=0;
    int cnt1=0;
    for(int i=0; i< n; i++)
    {
        if(a[i]==1&& b[i]==0)
        {
            cnta++;
        }
        else if(a[i]==0 && b[i]==1)
        {
            cntb++;
        }
        else if(a[i]==1 && b[i]==1)
        {
            cnt1++;
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










