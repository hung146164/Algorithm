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
int dp[32][2][32][32][32];
int visited[32][2][32][32][32];
int testid=1;
int sol(vector<int>& nums ,int& k, int curr=0, bool first=true,int cnt1=0,int cnt0=0
        ,int f1=-1)
{
    if(curr==nums.size())
    {
        if(f1==-1) return 0;
        if( ((curr-f1)+cnt1-1 )<=k ) return 1;
        return 0;
    }
    int ans=0;
    if(f1!=-1 && visited[curr][first][cnt1][cnt0][f1]==testid) return dp[curr][first][cnt1][cnt0][f1];
    if(f1!=-1) visited[curr][first][cnt1][cnt0][f1]=testid;
    if(first)
    {
        for(int i=0; i<=nums[curr]; i++)
        {
            ans+=sol(nums,k,curr+1,(first && i==nums[curr]),i==1?cnt1+1:cnt1,i==0?cnt0+1:cnt0,
                     (f1==-1 && i==1)?curr:f1);
        }
    }
    else{
        for(int i=0; i<=1; i++)
        {
            ans+=sol(nums,k,curr+1,false,i==1?cnt1+1:cnt1,i==0?cnt0+1:cnt0,(f1==-1 && i==1)?curr:f1);
        }
    }
    if(f1!=-1) dp[curr][first][cnt1][cnt0][f1]=ans;
    return  ans;
}
void solve()
{
    int n; cin>>n;
    int k; cin>>k;
    vector<int> nums;
    int cn=n;
    while(n)
    {
        nums.push_back((n%2));
        n/=2;
    }
    reverse(nums.begin(),nums.end());

    cout<<cn-sol(nums,k)<<el;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--)
    {
        solve();
        testid++;
    }
}







