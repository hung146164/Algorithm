
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

bool MEX(int curr ,vector<int>& nums)
{
    vector<int> h1(101);
    vector<int>h2(101);
    for(int i=0; i<=curr; i++)
    {
        h1[nums[i]]++;
    }
    for(int i=curr+1; i<nums.size(); i++)
    {
        h2[nums[i]]++;
    }
    int a1=0,a2=0;
    for(int i=0; i< 101; i++)
    {
        if(h1[i]==0)
        {
            a1=i;
            break;
        }
    }
    for(int i=0; i< 101; i++)
    {
        if(h2[i]==0)
        {
            a2=i;
            break;
        }
    }
    if(a1==a2)
    {
        return false;
    }
    return true;
}
void solve()
{
    int n; cin>>n;
    vector<int> nums;
    for(int i=0; i< n; i++)
    {
        int x; cin>>x;
        nums.push_back(x);
    }
    sort(nums.begin(),nums.end());
    for(int i=0; i< nums.size()-1; i++)
    {
        if(!MEX(i,nums))
        {
            cout<<"NO"<<el;
            return ;
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







