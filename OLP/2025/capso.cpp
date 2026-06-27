#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
typedef long long ll;
const ll N=1e6+5;
const ll mod=1e9+7;
const ll modr=1e9+9;
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
ll rut[N];
ll check[N];
void sang()
{
    for(ll i=0; i< N; i++)
    {
        rut[i]=i;
    }
    for(ll i=2; i<N; i++)
    {
        //cout<<i<<endl;
        ll val=i*i;
        for(ll j=val; j<N; j+=val)
        {
            while(rut[j]%val==0) rut[j]/=val;
        }
    }
}
vector<ll> sangscp()
{
    vector<ll> ans;
    for(ll i=2; i<=1000 ;i++)
    {
        ans.push_back(i*i);
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    sang();
    //cout<<so.size()<<el;
    ll n; cin>>n;
    vector<ll> nums;
    for(ll i=0; i< n; i++)
    {
        ll x; cin>>x;
        nums.push_back(rut[x]);
    }

    map<ll,ll> mp;
//    for(int i=0; i< nums.size(); i++)
//    {
//        cout<<nums[i]<<' ';
//    }
//    cout<<el;
    ll ans=0;
    for(ll i=0; i< nums.size(); i++)
    {
        ans+=mp[nums[i]];
        mp[nums[i]]++;
    }
    cout<<ans<<el;


}
