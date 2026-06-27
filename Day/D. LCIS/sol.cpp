/*
    Author: HungForree
    Link: https://codeforces.com/contest/10/problem/D
*/

#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
const ll N=500+5;
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
int f[N],pre[N];
int a[N],b[N];
void solve()
{
    int n; cin>>n;

    for(int i=1; i<=n;i++)
    {
        cin>>a[i];
    }
    int m; cin>>m;
    for(int i=1; i<=m; i++)
    {
        cin>>b[i];
    }
    int pos=0;
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        int best=0;
        int idx=0;
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j])
            {
                if(best+1>f[j])
                {
                    f[j]=best+1;
                    pre[j]=idx;

                }
            }
            if(a[i]>b[j])
            {
                if(f[j]>best)
                {
                    best=f[j];
                    idx=j;
                }
            }
        }
    }
    for(int j=1;j<=m; j++)
    {
        if(f[j]>ans)
        {
            ans=f[j];
            pos=j;
            //if(pos==50) cout<<i<<' '<<j<<' '<<a[i]<<' '<<b[j]<<el;
        }
    }
//    for(int i=0; i< 10; i++)
//    {
//        cout<<f[i]<<' ';
//    }
//    cout<<el;
//    for(int i=0; i<10; i++)
//    {
//        cout<<pre[i]<<' ';
//    }
   // cout<<pos<<el;
    vector<int> ds;
    cout<<ans<<el;
    while(pos!=0)
    {
        ds.push_back(b[pos]);
        pos=pre[pos];
    }
    for(int i=(int)ds.size()-1; i>=0 ;i--)
    {
        cout<<ds[i]<<' ';
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









