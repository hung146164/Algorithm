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

void solve()
{
   ll n, x; cin>>n>>x;
   vector<ll> a(n);
   vector<ll> b(n);
   vector<ll> c(n);
   for(ll i=0; i< n;i++)
   {
       cin>>a[i]>>b[i]>>c[i];
   }
   ll total=0;
   ll val=0;
   for(ll i=0; i< n; i++)
   {
       total+=a[i]*(b[i]-1);
       val=max(val,a[i]*b[i]-c[i]);
   }
   if(total>=x)
   {
       cout<<0<<el;
       return;
   }
   if(val<=0)
   {
       cout<<-1<<el;
       return;
   }
   else{
        int add=0;
        if((x-total)%val!=0) add=1;
        cout<<(x-total)/val+add<<el;
   }

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
        solve();
    }
}









