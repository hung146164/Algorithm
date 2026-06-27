#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll N=2e5+1;

ll maxll(ll a,ll b)
{
    if(a>b) return a;
    return b;
}
ll minll(ll a,ll b)
{
    if(a>b) return b;
    return a;
}
ll gdc(ll a, ll b)
{
    if(b==0) return a;
    return gdc(b,a%b);
}


ll gt[N];
ll ingt[N];

ll tohop(ll n,ll k)
{
    return (gt[n]*ingt[n-k]%mod)*ingt[k]%mod;
}
ll powll(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a%mod;
        }
        b/=2;
        a=a*a%mod;
    }
    return ans;
}

void process()
{
    gt[0]=ingt[0]=1;
    for(ll i=1; i<N; i++)
    {
        gt[i]=gt[i-1]*i%mod;
        ingt[i]=ingt[i-1]*powll(i,mod-2)%mod;
    }

}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    process();
    ll t; cin>>t;
    while(t--)
    {
        ll n,m,k; cin>>n>>m>>k;

        vector<ll> nums;
        for(ll i=0; i< n; i++)
        {
            ll x; cin>>x;
            nums.push_back(x);
        }
        if(m==1)
        {
            cout<<n<<'\n';
            continue;
        }
        vector<ll> C(n);
        for(ll i=m-2; i<n; i++)
        {
            C[i]=tohop(i,m-2)+(i-1>=0?C[i-1]:0);
        }
//        for(int i=0; i<n; i++) cout<<C[i]<<' ';
//        cout<<endl;
        sort(nums.begin(),nums.end());
        ll ans=0;
        for(ll i=0; i< n; i++)
        {
            ll index=prev(upper_bound(nums.begin(),nums.end(),nums[i]+k))-nums.begin();
            //cout<<index<<endl;
            if(index-i+1<m) continue;
            ll l=i+m-1;
            ll r=index;

            ans=(ans+(( (r-i-1>=0?C[r-i-1]:0)-(l-i-2>=0?C[l-i-2]:0))%mod+mod)%mod)%mod;
        }

        cout<<ans<<'\n';

    }
}


