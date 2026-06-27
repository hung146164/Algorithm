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
    string a, b; cin>>a>>b;
    int ans=INT_MAX;
    int ans1=-1,ans2=-1;
    for(int i=0;i<26; i++)
    {
        int l=1,r=b.size()-2;
        while(l<a.size() && (a[l]-'a')!=i)
        {
            l++;
        }
        while(r>=0 && (b[r]-'a')!=i)
        {
            r--;
        }
        if(r<0 || l>=a.size()) continue;
        if(l+(int)b.size()-r<ans)
        {            ans=l+(int)b.size()-r;
            //cout<<l<<' '<<r<<el;
            ans1=l;
            ans2=r;
        }
    }
    if(ans1==-1 || ans2==-1)
    {
        cout<<-1<<el;
        return;
    }
    //cout<<ans2<<' '<<b[ans2]<<el;
    for(int i=0; i<ans1;i++)
    {
        cout<<a[i];
    }
    //cout<<el;
    for(int i=ans2;i<b.size(); i++)
    {
        cout<<b[i];
    }
    cout<<el;
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









