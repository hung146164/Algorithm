/*
    Author: HungForree
    Link: https://codeforces.com/problemset/problem/1036/C
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
//int nums[N];
//int dp[20][4][2];
//int cache[20][4][2];
//int id=1;
//int sol(string& s,int curr=0,bool first=true,int cnt=0)
//{
//    if(cnt>3) return 0;
//    //cout<<curr<<' '<<first<<' '<<v1<<' '<<v2<<' '<<v3<<' '<<cnt<<el;
//    if(curr==s.size()) return 1;
//    if(cache[curr][cnt][first]==id) return dp[curr][cnt][first];
//    cache[curr][cnt][first]=id;
//    int ans=0;
//    for(int i=0; i<= 9 ;i++)
//    {
//        if(first && i>s[curr]-'0') continue;
//        bool nextfirst=(i==s[curr]-'0'?true:false)&first;
//        int add=(i==0?0:1);
//        ans+=sol(s,curr+1,nextfirst,cnt+add);
//    }
//    return dp[curr][cnt][first]=ans;
//}
ll gt[20];
ll pow9[4];
ll C(ll n,ll k)
{
    if(k>n) return 0;
    return gt[n]/(gt[n-k]*gt[k]);
}
ll sol(string& s)
{
    ll n=s.size();
    ll ans=0;
    ll have=0;


    for(ll i=0; i< n; i++)
    {
        ll need=3-have;
        if(need<0) continue;
        ll val=s[i]-'0'-1;
        for(ll j=0; j<=val; j++)
        {
            if(j==0)
            {
                ans+=C(n-i-1,need)*pow9[need];
            }
            else if(need>0)
            {
                ans+=C(n-i-1,need-1)*pow9[need-1];
            }
        }
        if(s[i]-'0'!=0) have++;
    }
    return ans;
}
void solve()
{
    ll l, r; cin>>l>>r;
    string s=to_string(r);
    string t=to_string(l-1);
//    ll ans1=sol(s);
//    id++;
//    ll ans2=sol(t);
//    cout<<ans1-ans2<<el;
    cout<<sol(s)<<el;
    cout<<sol(s)-sol(t)<<el;
}
void process()
{
    pow9[0]=1;
    for(ll i=1;i<4; i++)
    {
        pow9[i]*=9;
    }
    gt[0]=1;
    for(ll i=1;i<20; i++)
    {
        gt[i]=gt[i-1]*i;
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    process();
    ll t; cin>>t;
    while(t--)
    {
        solve();
        //id++;
    }
}










