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
const ll mod=998244353;
const ll modr=1e9+9;

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
ll gt[55];
ll ingt[55];
void process()
{
    gt[0]=ingt[0]=1;
    for(ll i=1; i< 55; i++)
    {
        gt[i]=gt[i-1]*i%mod;
        ingt[i]=ingt[i-1]*powll(i,mod-2);
    }

}
ll C(ll n,ll k)
{
    if(k<0 || k>n) return 0;
    return (gt[n]*ingt[k]%mod)*ingt[n-k]%mod;
}
bool can(ll lon,ll du,vector<ll>& nums)
{
    for(ll i=1; i< nums.size(); i++)
    {
        if(nums[i]<lon-1)
        {
            du-=(lon-1-nums[i]);
        }
        if(du<0) return false;
    }
    return true;

}
void sol()
{
    ll n; cin>>n;
    vector<ll> nums(n+1);
    bool allzero=true;
    for(ll i=0; i< n+1; i++)
    {
        cin>>nums[i];
        if(nums[i]!=0) allzero=false;
    }
    if(allzero)
    {
        cout<<gt[n]<<el;
        return;
    }
    ll start=0;
    ll du=nums[0];
    for(ll i=1; i< n+1; i++)
    {
        start=max(start,nums[i]);
    }
    ll l=start,r=2000000;
    while(l<=r)
    {
        ll m=l+(r-l)/2;
        if(can(m,du,nums))
        {
            l=m+1;
        }
        else{
            r=m-1;
        }
    }
    ll lonhon=r;
    if(r<start)
    {
        cout<<0<<el;
        return;
    }

    for(ll i=1;i < nums.size(); i++)
    {
        if(nums[i]<r-1)
        {
            du-=(r-1-nums[i]);
            nums[i]=r-1;
        }
    }
    ll moi=0,conlai=n,san=0;
    for(ll i=1; i< nums.size(); i++)
    {
        if(nums[i]==lonhon)
        {
            san++;
            conlai--;
            continue;
        }
        if(du)
        {
            moi++;
            conlai--;
            du--;
        }

    }
    //cout<<moi<<' '<<conlai<<' '<<san<<el;
    cout<<(gt[moi+san]*gt[conlai]%mod)*C(conlai+moi,moi)%mod<<el;

}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    process();
    ll t; cin>>t;
    while(t--)
    {
        sol();
    }
}




