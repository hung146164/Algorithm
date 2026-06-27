/*
    Author: HungForree
    Link: https://codeforces.com/problemset/problem/383/B
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
ll dx[]{1,1,1};
ll dy[]{0,-1,1};
bool cmp(const pair<int,int>& a,const pair<int,int>& b)
{
    if(a.first==b.first)
    {
        return a.second>b.second;
    }
    return a.first<b.first;
}
void solve()
{
    ll n; cin>>n;
    ll m; cin>>m;
    vector<pair<ll,ll>> pos(m);
    for(ll i=0; i< m; i++)
    {
        cin>>pos[i].first>>pos[i].second;
    }
    sort(pos.begin(),pos.end(),cmp);
    map<pair<ll,ll>,ll> dp;
    //dp.reserve(m);
    for(ll i=0; i< pos.size(); i++)
    {
        if(pos[i].second==n)
        {
           dp[pos[i]]=pos[i].first;
           if(pos[i].first==n)
           {
               cout<<-1<<el;
               return;
           }
        }
        else dp[pos[i]]=1;
    }
    ll maxx=0;
    for(ll i=0; i< pos.size(); i++)
    {
        for(ll j=0; j< 3; j++)
        {
            ll tox=pos[i].first+dx[j];
            ll toy=pos[i].second+dy[j];
            if(dp.find({tox,toy})!=dp.end())
            {

                dp[{tox,toy}]=max(dp[{tox,toy}],1+dp[pos[i]]);
               // cout<<toy<<' '<<
                if(toy==1 && dp[{tox,toy}] ==tox )
                {
                    cout<<-1<<el;
                    return;
                }
                maxx=max(maxx,dp[{tox,toy}]);
            }
        }
        ll tox=pos[i].first;
        ll toy=pos[i].second-1;
        if(dp.find({tox,toy})!=dp.end())
        {
            dp[{tox,toy}]=max(dp[{tox,toy}],dp[pos[i]]);
        }
    }
    //cout<<maxx<<el;
    if(maxx==n)
    {
        cout<<-1<<el;
        return;
    }
    cout<<2*(n-1)<<el;

}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll t; t=1;
    while(t--)
    {
        solve();
    }
}









