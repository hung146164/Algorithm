#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=1e3+1;
const int mod=1e9+7;
ll dp[N][N];
vector<ll> timuoc(ll a)
{
    vector<ll> nums;
    for(ll i=1; i*i<=a;i++)
    {
        if(a%i==0)
        {
            nums.push_back(i);
            if(a/i!=i)
            {
                nums.push_back(a/i);
            }
        }
    }
    sort(nums.begin(),nums.end());
    return nums;
}
ll fin(ll a, ll b)
{
    if(a<b) swap(a,b);
    ll ans=0;
    vector<ll> uoc=timuoc(a);
    ll i=0;
    while(i<uoc.size() && b>=uoc[i])
    {
        if(b%uoc[i]==0)
        {
            ans+=(a/uoc[i])*(b/uoc[i]);
            ans%=mod;
        }
        i++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("GCDS.INP","r",stdin);
    freopen("GCDS.OUT","w",stdout);

    ll n,q;cin>>n>>q;
    vector<ll> nums;
    for(ll i=0;i<n; i++)
    {
        ll x; cin>>x;
        nums.push_back(x);
    }
    ll total=0;
    for(ll i=0; i< n; i++)
    {
        for(ll j=i+1; j<n; j++)
        {


            ll a=i,b=j;
            if(a>b) swap(a,b);

            ll curr=fin(nums[a],nums[b]);
            total+=curr;
            total%=mod;
            dp[a][b]=curr;
        }
    }
    cout<<total<<'\n';
    while(q--)
    {
        ll x,y; cin>>x>>y;
        x--;
        nums[x]=y;
        for(ll j=0; j<nums.size(); j++)
        {
            if(j==x) continue;
            ll a=x,b=j;
            if(a>b) swap(a,b);

            total=(total-dp[a][b] %mod +mod)%mod;
            ll curr=fin(nums[a],nums[b]);
            total+=curr;
            total%=mod;
            dp[a][b]=curr;
        }
        cout<<total<<'\n';
    }

}
