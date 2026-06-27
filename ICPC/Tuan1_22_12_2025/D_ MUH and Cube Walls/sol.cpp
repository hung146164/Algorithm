#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
//typedef __int128 i128;
const ll N=2e5+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
//ll base=rng() % 500 +300;
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

ll a1[N], a2[N], ar1[N],ar2[N],hash1[N],hash2[N];
ll n,m;
ll base=1000003;
ll powbase[N];
ll inbase[N];
void nen()
{
    vector<ll> clone;
    for(ll i=0; i<n-1; i++)
    {
        clone.push_back(a1[i]);
    }
    for(ll i=0;i<m-1; i++)
    {
        clone.push_back(a2[i]);
    }
    sort(clone.begin(),clone.end());
    clone.erase(unique(clone.begin(),clone.end()),clone.end());
    for(ll i=0; i< n-1; i++)
    {
        ar1[i+1]=lower_bound(clone.begin(),clone.end(),a1[i])-clone.begin()+1;
    }
    for(ll i=0; i< m-1; i++)
    {
        ar2[i+1]=lower_bound(clone.begin(),clone.end(),a2[i])-clone.begin()+1;
    }
//    for(ll i=1;i<n;i++)
//    {
//        cout<<ar1[i]<<' ';
//    }
//    cout<<el;
//    for(ll i=1;i< m; i++)
//    {
//        cout<<ar2[i]<<' ';
//    }
//    cout<<el;


}
void process()
{
    powbase[0]=inbase[0]=1;
    ll ibase=powll(base,mod-2);
    for(ll i=1; i<N; i++)
    {
        powbase[i]=powbase[i-1]*base%mod;
        inbase[i]=inbase[i-1]*ibase%mod;
    }
}
ll get1(ll a,ll b)
{
    return (hash1[b]-hash1[a-1]+mod)*inbase[a]%mod;
}
ll get2(ll a,ll b)
{
    return (hash2[b]-hash2[a-1]+mod)*inbase[a]%mod;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    process();
     cin>>n>>m;
    for(ll i=0; i< n; i++)
    {
        cin>>a1[i];
    }
    for(ll i=0; i<m ;i++)
    {
        cin>>a2[i];
    }
    for(ll i=1;i<n; i++)
    {
        a1[i-1]=a1[i]-a1[i-1];
    }
    for(ll i=1; i< m; i++)
    {
        a2[i-1]=a2[i]-a2[i-1];
    }

    nen();

    for(ll i=1;i<n; i++)
    {
        hash1[i]=(hash1[i-1]+powbase[i-1]*ar1[i]%mod)%mod;
    }
    for(ll i=1; i< m; i++)
    {
        hash2[i]=(hash2[i-1]+powbase[i-1]*ar2[i]%mod)%mod;
    }
//    for(int i=0; i< n;i ++)
//    {
//        cout<<hash1[i]<<' ';
//    }
//    cout<<el;
//    for(int i=0;i<m;i++)
//    {
//        cout<<hash2[i]<<' ';
//    }
//    cout<<el;
    ll ans=0;
    for(ll i=m-1;i<n; i++)
    {
        //cout<<get1(i-(m-1)+1,i)<<' '<<get2(1,m-1)<<el;
        if(get1(i-(m-1)+1,i)==get2(1,m-1))
        {
            ans++;
        }
    }
    cout<<ans<<el;

}


