/*
    Author: HungForree
    Link: https://codeforces.com/problemset/problem/86/D
*/

#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
const ll N=2e5+5;
const ll M=1e6+6;
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
ll nums[N];
ll cnt[M];
ll ans=0;

void add(ll index)
{
    ans-=cnt[nums[index]]*cnt[nums[index]]*nums[index];
    cnt[nums[index]]++;
    ans+=cnt[nums[index]]*cnt[nums[index]]*nums[index];
}
void rm(ll index)
{
    ans-=cnt[nums[index]]*cnt[nums[index]]*nums[index];
    cnt[nums[index]]--;
    ans+=cnt[nums[index]]*cnt[nums[index]]*nums[index];
}
void solve()
{
    ll n,q; cin>>n>>q;
    for(ll i=1;i<=n; i++)
    {
        cin>>nums[i];
    }
    vector<vector<ll>> query;
    ll len=0;
    for(ll i=0;i<q;i++){
        ll a, b; cin>>a>>b;
        query.push_back({a,b,i});
        len=max(len,b);
    }
    ll L=sqrt(len);

    auto cmp=[&](vector<ll>& a, vector<ll>& b)
    {
        ll a_block=a[0]/L;
        ll b_block=b[0]/L;
        if(a_block==b_block)
        {
            if(a_block%2==0)
            {
                return a[1]<b[1];
            }
            else
            {
                return a[1]>b[1];
            }
        }
        return a_block<b_block;
    };
    sort(query.begin(),query.end(),cmp);
//    cout<<"H"<<el;
//    for(ll i=0;i<q; i++)
//    {
//        cout<<query[i][0]<<' '<<query[i][1]<<el;
//    }
    set<ll> can;
    for(ll i=query[0][0];i<=query[0][1];i++)
    {
        cnt[nums[i]]++;
        can.insert(nums[i]);
    }

    for(auto& i: can)
    {
        ans+=cnt[i]*cnt[i]*i;
    }

    vector<ll> re(q);
    re[query[0][2]]=ans;
    ll left=query[0][0];
    ll right=query[0][1];
    for(ll i=1;i<q;i++)
    {
        while(left<query[i][0])
        {
            rm(left);
            left++;
        }
        while(left>query[i][0])
        {

            left--;
            add(left);
        }
        while(right<query[i][1])
        {

            right++;
            add(right);
        }
        while(right>query[i][1])
        {
            rm(right);
            right--;
        }
        re[query[i][2]]=ans;
    }
    for(ll i=0;i<q;i++)
    {
        cout<<re[i]<<el;
    }

}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll t;t=1;
    while(t--)
    {
        solve();
    }
}










