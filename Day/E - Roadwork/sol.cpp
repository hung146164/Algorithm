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
vector<int> nums[N];
int tree[N];
void solve()
{
    for(int i=1;i<N; i++)
    {
        tree[i]=INT_MAX;
    }
    int n,q; cin>>n>>q;
    for(int i=1; i<=n; i++)
    {
        int a,b,c; cin>>a>>b>>c;
        nums[i]={a,b,c};
    }
    vector<int>query;
    for(int i=0; i<q; i++){
        cin>>query[i];
    }
    vector<vector<int>> cnt(q+1);
    for(int i=1;i<=n; i++)
    {
        int s=nums[i][0];
        int t=nums[i][1];
        int x=nums[i][2];

        int left=max(0,l-x);
        int right=r-1-x;

        cnt[lower_bound(query.begin(),query.end(),left)-query.begin()].push_back(x);
        cnt[upper_bound(query.begin(),query.end(),right)-query.begin()].push_back(-x);
    }
    queue<int> q;
    map<ll,ll> hethan;
    for(int i=0;i<query.size(); i++)
    {

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










