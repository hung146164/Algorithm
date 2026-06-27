
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

void solve()
{
    int n; cin>>n;
    vector<pair<int,int>> nums;
    for(int i=0;i<n; i++)
    {
        int x; cin>>x;
        nums.push_back({i,x%2});
    }
    sort(nums.begin(), nums.end());
    for(int i=1; i< nums.size(); i++)
    {
        if(nums[i].second==nums[i-1].second)
        {
            cout<<"NO"<<el;
            return;
        }
    }
    cout<<"YES"<<el;

}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--)
    {
        solve();
    }
}







