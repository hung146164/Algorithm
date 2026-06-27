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
const ll N=2e5+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
using i128 = __int128;
constexpr i64 inf = 1E18;

ll id=1;
ll dp[N][2];
int cache[N][2];
ll sol(vector<pair<ll,vector<ll>>>& nums,ll& bx, ll& by,ll curr=1, bool pup=false)
{
    ll prex=nums[curr-1].first;
    ll prey=nums[curr-1].second[(pup?nums[curr-1].second.size()-1:0)];
    //cout<<prex<<' '<<prey<<el;
    if(curr==nums.size())
    {
        return abs(prex-bx)+abs(prey-by);
    }
    if(cache[curr][pup]==id) return dp[curr][pup];
    cache[curr][pup]=id;
    ll ans=inf;

    ll down=nums[curr].second[0];
    ll up = nums[curr].second[nums[curr].second.size()-1];

    //up
    ans=min(ans,abs(nums[curr].first-prex)+abs(down-up)+abs(down-prey)+sol(nums,bx,by,curr+1,true));
    //down

    ans=min(ans,abs(nums[curr].first-prex)+abs(down-up)+abs(up-prey)+sol(nums,bx,by,curr+1,false));

    return dp[curr][pup]=ans;
}
void solve()
{
    ll n, ax,ay,bx,by; cin>>n>>ax>>ay>>bx>>by;
    map<ll,vector<ll>> mp;
    vector<ll> a(n),b(n);
    for(ll i=0; i<n; i++)
    {
        cin>>a[i];

    }
    for(ll i=0; i<n; i++)
    {
        cin>>b[i];

    }
    for(ll i=0; i< n; i++)
    {
        mp[a[i]].push_back(b[i]);
    }
    vector<pair<ll,vector<ll>>> nums;
    nums.push_back({ax,{ay}});
    for(auto& i : mp)
    {
        nums.push_back(i);
    }

    for(ll i=0; i< nums.size(); i++)
    {
        sort(nums[i].second.begin(),nums[i].second.end());
    }
//     for(ll i=0; i< nums.size(); i++)
//    {
//        cout<<nums[i].first<<":";
//        for(auto j: nums[i].second)
//        {
//            cout<<j<<' ';
//        }
//        cout<<el;
//    }

    cout<<sol(nums,bx,by)<<el;
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
        id++;
    }
}










