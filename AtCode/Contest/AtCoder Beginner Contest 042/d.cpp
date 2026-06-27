#include<bits/stdc++.h>
#define ll long long
#define en "\n"
#define inf 1e18
//cout << setprecision(7) << fixed
#define mod 1000000007
using namespace std;
#define BIT(x, i) (((i) >> (x))&1)
#define find(s,a) s.find(a)!=s.end()
const ll N=3e5+5;
ll powll(ll a,ll b)
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
ll gt[N], ingt[N];
void process()
{
    gt[0]=ingt[0]=1;
    for(ll i=1; i<N; i++)
    {
        gt[i]=gt[i-1]*i%mod;
        ingt[i]=ingt[i-1]*powll(i,mod-2)%mod;
    }
}
ll C(ll a, ll b)
{
    return ((gt[a]*ingt[a-b])%mod)*ingt[b]%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    process();
    ll n,m; cin>>n>>m;
    ll a, b; cin>>a>>b;

    ll ans=0;
    for(ll i=1;i<=n-a; i++)
    {
        //(1,1) -> (i,b) * (i,b+1) -> (n,m)

        ans=(ans+C(i-1+b-1,i-1)*C(n-i+m-b-1,n-i)%mod)%mod;
    }
    cout<<ans<<en;

}

