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
const ll N=1e5+5;
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
vector<pair<int,int>> block[N];
void solve()
{
    int n; cin>>n;

    for(int i=0; i< n; i++)
    {
        int k,x1,x2; cin>>k>>x1>>x2;
        x2--;
        vector<int> clone;
        int sum=0;
        for(int j=0; j< k; j++)
        {
            int x; cin>>x;
            clone.push_back(x);
            sum+=x;
        }
        block[i].push_back({x1,x2-sum});
        int val=0;
        for(int j=0; j< k ;j++)
        {
            sum-=clone[j];
            val+=clone[j];
            block[i].push_back({x1+val,x2-sum});
        }
    }
    for(int i=0; i< n; i++)
    {
        for(int j=0; j< block[i].size(); j++)
        {
            cout<<block[i][j].first<<' '<<block[i][j].second<<", ";
        }
        cout<<el;
    }
    if(n==1)
    {
        int ans=0;
        for(auto& [l,r]: block[0])
        {
            ans=max(ans,r-l+1);
        }
        return;
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









