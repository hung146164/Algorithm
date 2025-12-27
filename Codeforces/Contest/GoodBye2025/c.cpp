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
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll t; cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        vector<ll> nums(n);
        for(ll i=0; i< n; i++) cin>>nums[i];
        vector<ll> toiuu,tru(1,0);
        for(ll i=1; i< n; i++)
        {
            tru.push_back(tru[i-1]-nums[i]);
        }
        ll val=nums[0];
        toiuu.push_back(val);
        for(ll i=1; i< n; i++)
        {
            if(nums[i]<0) val-=nums[i];
            else val+=nums[i];
            toiuu.push_back(val);
        }
//        for(int i=0; i< toiuu.size(); i++)
//        {
//            cout<<toiuu[i]<<' ';
//        }
//        cout<<el;
//        for(int i=0; i< tru.size(); i++)
//        {
//            cout<<tru[i]<<' ';
//        }
//        cout<<el;
        ll ans=-inf;
        for(ll i=0;i<n; i++)
        {
            ans=max(ans,(i-1>=0?toiuu[i-1]:0)+tru[n-1]-tru[i]);
        }
        cout<<ans<<el;
    }
}



