#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll v2(ll n)
{
    ll c=2;
    ll ans=0;
    while( (n/c)!=0)
    {
        ans+=n/c;
        c*=2;
    }
    return ans;
}
bool chiahetcho2(ll m, ll i)
{
    int kq= v2(m)-v2(m-i)-v2(i);
    return kq>0;
}
ll sol(vector<ll>& nums)
{
    if(nums.size()==1) return nums[0];
    if(nums.size()==2) return nums[0]^nums[1];

    ll n=nums.size();

    ll m=n-1;
    ll ans=0;
    for(ll i=0; i< nums.size(); i++)
    {

        if(chiahetcho2(m,i)) continue;
        ans^=nums[i];
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;cin>>n;

    vector<ll> nums;
    for(ll i=0; i< n; i++)
    {
        ll x; cin>>x;
        nums.push_back(x);
    }

    cout<<sol(nums)<<'\n';
}
