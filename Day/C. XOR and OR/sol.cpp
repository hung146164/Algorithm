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
    string s1,s2; cin>>s1>>s2;
    if(s1.size()!=s2.size()) {cout<<"NO"<<el; return;}
    int cnt1=0;
    for(int i=0; i< s1.size(); i++)
    {
        if(s1[i]=='1') cnt1++;
    }
    int cnt2=0;
    for(int i=0; i< s2.size(); i++)
    {
        if(s2[i]=='1') cnt2++;
    }
    if(cnt1==0 && s1!=s2) cout<<"NO"<<el;
    else if(cnt1>0 && cnt2==0) cout<<"NO"<<el;
    else cout<<"YES"<<el;
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









