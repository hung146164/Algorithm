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
const ll inf=1e18;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll base=rng() % 500 +300;
ll powll(ll a, ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a%mod;
        }
        a=a*a%mod;
        b/=2;
    }
    return ans;
}
void solve()
{
    int n; cin>>n;
    vector<int> nums(n);
    unordered_map<int,int> dp;
    for(int i=0; i< n;i++)
    {
        cin>>nums[i];
        dp[nums[i]]++;
    }
    vector<pair<int,int>> m;
    for(auto& i: dp) m.push_back(i);
    sort(m.begin(),m.end());
    int ans=0;
    vector<int> a,b;
    for(int i=0;i<m.size()-1; i++)
    {
        a.push_back(m[i].first);
        if(m[i].second>1)
        {
            b.push_back(m[i].first);
        }
    }
    a.push_back(m[m.size()-1].first);
    cout<<a.size()+b.size()<<el;
    for(int i=0; i< a.size(); i++) cout<<a[i]<<' ';
    for(int i=b.size()-1; i>=0; i--) cout<<b[i]<<' ';


}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int t=1;
    while(t--)
    {
        solve();
    }
}






