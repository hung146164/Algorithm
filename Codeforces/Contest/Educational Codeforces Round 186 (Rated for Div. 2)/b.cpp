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

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int t; cin>>t;
    while(t--)
    {
        int a, b; cin>>a>>b;
        int clonea=a,cloneb=b;
        int ans=0,val=0;
        int i=0;
        while(a>0 || b>0)
        {
            if(i%2==1)
            {
                a-=pow(2,i);
            }
            else
            {
                b-=pow(2,i);
            }
            if(a>=0 && b>=0)
            {
                ans++;
            }
            i++;
        }
        a=clonea;
        b=cloneb;
        i=0;
        while(a>0 || b>0)
        {
            if(i%2==0)
            {
                a-=pow(2,i);
            }
            else
            {
                b-=pow(2,i);
            }
            if(a>=0 && b>=0)
            {
                val++;
            }
            i++;
        }
        ans=max(ans,val);
        cout<<ans<<el;

    }
}




