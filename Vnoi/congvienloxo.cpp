#include<bits/stdc++.h>
#define ll long long
#define en "\n"
#define inf 1e18
//cout << setprecision(7) << fixed
#define MOD 1000000007
using namespace std;
#define BIT(x, i) (((i) >> (x))&1)
#define find(s,a) s.find(a)!=s.end()
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin>>n;
    vector<ll> nums;
    for(ll i=0; i< n; i++)
    {
        ll x; cin>>x;
        nums.push_back(x);
    }
    vector<ll>diff(n+3);
    ll curr=0;
    ll ans=0;
    for(ll i=0; i< nums.size(); i++)
    {
        curr+=diff[i];
        ll need=nums[i]-1;
        if(curr<need)
        {
            ans+=need-curr;
            diff[i+2]+=1;
            if(i+2+need<n+3) diff[i+2+need]-=1;
        }
        else{
            diff[i+2]+=1;
            if(i+2+need<n+3) diff[i+2+need]-=1;
            diff[i+1]+=curr-need;
            diff[i+2]-=curr-need;
        }
    }
    cout<<ans<<'\n';
}

