#include<bits/stdc++.h>
#define en "\n"
#define inf 1e18
//cout << setprecision(7) << fixed
using namespace std;
#define BIT(x, i) (((i) >> (x))&1)
#define find(s,a) s.find(a)!=s.end()
typedef long long ll;
const ll mod=1e9+7;
const ll N=1e5+5;
ll gt[N];
ll ingt[N];

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
void process()
{
    gt[0]=ingt[0]=1;
    for(ll i=1; i<N ;i++)
    {
        gt[i]=gt[i-1]*i%mod;
        ingt[i]=ingt[i-1]*powll(i,mod-2)%mod;
    }
}
ll C(ll a,ll b)
{
    if(b>a) return 0;
    return (gt[a]*ingt[a-b]%mod)*ingt[b]%mod;
}
//ll calsum(ll n)
//{
//    ll ans=0;
//    for(ll i=1; i<=n; i++)
//    {
//        ans=(ans+i*C(n,i)%mod)%mod;
//    }
//    return ans;
//}
signed main()
{
//    freopen("help.in","r",stdin);
//    freopen("help.out","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //process();
    ll n; cin>>n;
    vector<pair<ll,ll>> sub;
    for(ll i=0; i< n; i++)
    {
        ll a, b; cin>>a>>b;
        sub.push_back({a,b});
    }
    sort(sub.begin(),sub.end());
    ll ans=n*powll(2,n-1)%mod;
    //cout<<ans<<en;
    for(ll i=0; i< sub.size(); i++)
    {
        ll l=sub[i].first;
        ll r=sub[i].second;
        ll pos=lower_bound(sub.begin(),sub.end(),make_pair(r,0LL))-sub.begin();
        ll dist=pos-i-1;
//        cout<<"Dist"<<' '<<dist<<en;
        ans=((ans-dist*powll(2,dist-1)%mod)%mod+mod)%mod;
    }
    cout<<ans<<en;

}

