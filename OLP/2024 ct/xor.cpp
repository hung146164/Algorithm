#include<bits/stdc++.h>
#define ll long long
#define el "\n"
#define MAX 1e18
#define PI 3.1415926535897932384626433832795028841971693993751058209
//cout << setprecision(7) << fixed
#define MOD 1000000007
#define MODR 998244353
#define fi first
#define se second
#define all(v) v.begin(),v.end()
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
//template <typename T>
//#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
//freopen(".INP", "r", stdin);
//freopen(".OUT", "w", stdout);
ll gcd(ll x,ll y)
{
    if(x==0) return y;
    else return gcd(y%x,x);
}
ll min(ll x,ll y)
{
    if(x>y) return y;
    else return x;
}
ll max(ll x,ll y)
{
    if(x<y) return y;
    else return x;
}
const long long MOR=998244353;
#define BIT(x, i) (((i) >> (x))&1)
#define rep(i,n) for(int i=0,_n=n;i<n;i++)
ll xorp(ll n) {
    if (n % 4 == 0) return n;
    else if (n % 4 == 1) return 1;
    else if (n % 4 == 2) return n + 1;
    else return 0;
}
#define find(s,a) s.find(a)!=s.end()
ll dp[200001];
void ckn()
{
	dp[0]=0;
	ll ans=0,p;
	for(ll i=1;i<=200001;i++)
	{
		ans=0;
		p=i;
		while(p%2==0) p=p/2,ans+=1;
		dp[i]=dp[i-1]+ans;
	}
	for(int i=1; i<=20;i++) cout<<dp[i]<<' ';
    cout<<endl;
}
void solve()
{
   ll n;
   cin>>n;
   vector<ll> v(n);
   for(auto &x:v) cin>>x;
   ll ans=0;
   for(ll i=0;i<=n-1;i++)
   {
   	 if(dp[i]+dp[n-1-i]>=dp[n-1]) ans=(ans^v[i]);
   }
   cout<<ans;
}
int main()
{
ckn();
//freopen("DMK.INP", "r", stdin);
//freopen("DMK.OUT", "w", stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);
ll t=1;
//cin>>t;
while(t--) solve();
return 0;
}

