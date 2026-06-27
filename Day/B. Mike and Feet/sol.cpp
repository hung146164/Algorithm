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
int nums[N];
int l[N],r[N],ans[N];
void solve()
{
    int n; cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>nums[i];
    }
    //cout<<l[2]<<el;
    stack<pair<int,int>> st;
    st.push({0,0});

    for(int i=1; i<=n; i++)
    {
        while(st.top().first>=nums[i]) st.pop();
        l[i]=st.top().second+1;
        st.push({nums[i],i});
    }
    while(!st.empty()) st.pop();
    st.push({0,n+1});

    for(int i=n;i>=1; i--)
    {
        while(st.top().first>=nums[i]) st.pop();
        r[i]=st.top().second-1;
        st.push({nums[i],i});
        ans[r[i]-l[i]+1]=max(ans[r[i]-l[i]+1],nums[i]);
    }
    for(int i=n;i>=1;i--)
    {
        ans[i]=max(ans[i+1],ans[i]);
    }
    for(int i=1;i<=n; i++) cout<<ans[i]<<' ';

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










