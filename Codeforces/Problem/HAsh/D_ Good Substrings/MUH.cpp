#include<bits/stdc++.h>
#define ll long long
#define en "\n"
#define inf 1e18

using namespace std;
const ll mod=(1LL<<61)-1;
const ll modr=2e9+11;
const ll N =2e5+5;
ll pow31[N],in31[N],pow31r[N],in31r[N];
ll hash1[N];
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
    pow31[0]=in31[0]=1;
    ll i31=powll(modr,mod-2);

    for(ll i=1; i< N; i++)
    {
        pow31[i]=pow31[i-1]*modr%mod;
        in31[i]=in31[i-1]*i31%mod;
    }
}
ll get(ll a,ll b)
{
    return (((hash1[b]-hash1[a])%mod+mod)%mod)*in31[a]%mod;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    process();
    ll n,m; cin>>n>>m;
    vector<ll> nums(n);
    vector<ll> mums(m);
    for(ll i=0;i< n; i++)
    {
        cin>>nums[i];
    }
    for(ll i=0; i< m; i++)
    {
        cin>>mums[i];
    }
    ll ans=0;
    for(int i=0;i< 10 ;i++)
    {
        cout<<pow31[i]<<' ';
    }
    cout<<en;
    for(int i=0; i< 10; i++)
    {
        cout<<in31[i]<<' ';
    }
    cout<<en;

    vector<ll> arr1(n-1);
    vector<ll> arr2(n-1);
    for(ll i=1; i< n; i++)
    {
        arr1[i]=nums[i]-nums[i-1]+1e9+1;
    }
    for(ll i=1; i< m; i++)
    {
        arr2[i]= mums[i]-mums[i-1]+1e9+1;
    }

    for(ll i=0; i<arr1.size(); i++)
    {
        hash1[i+1]=(hash1[i]+arr1[i]*pow31[i]%mod)%mod;
    }
    for(int i=0; i< 10; i++)
    {
        cout<<hash1[i]<<' ';
    }
    cout<<en;
    ll cp=0;
    for(ll i=0; i<arr2.size(); i++)
    {
        cp=(cp+arr2[i]*pow31[i]%mod)%mod;
    }
    cout<<cp<<en;
    for(ll i=m;i<=n; i++)
    {
        cout<<get(i-m,i)<<en;
        if(get(i-m,i)==cp) ans++;
    }
    cout<<ans<<en;
}

