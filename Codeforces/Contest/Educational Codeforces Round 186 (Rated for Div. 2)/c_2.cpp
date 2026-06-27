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
void sol()
{
    ll n; cin>>n;
    vector<ll> a(n),b(n),c(n);
    for(ll i=0; i<n; i++)
    {
        cin>>a[i];
    }for(ll i=0; i<n; i++)
    {
        cin>>b[i];
    }for(ll i=0; i<n; i++)
    {
        cin>>c[i];
    }
    vector<bool> c1(n),c2(n);
    int cnt1=0,cnt2=0;
    for(ll i=0; i< n; i++)
    {
        for(ll j=0; j< n; j++)
        {
            if(a[i]>=b[j] && !c1[(i-j+n)%n])
            {
                cnt1++;
                c1[(i-j+n)%n]=true;
            }
        }
    }
    for(ll i=0; i< n; i++)
    {
        for(ll j=0; j< n; j++)
        {
            if(b[i]>=c[j] && !c2[(i-j+n)%n])
            {
                cnt2++;
                c2[(i-j+n)%n]=true;
            }
        }
    }
   // cout<<s1.size()<<' '<<s2.size()<<el;
    cout<<n*n*n-n*n*cnt1-n*n*cnt2+n*cnt1*cnt2<<el;

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
        sol();
    }
}




