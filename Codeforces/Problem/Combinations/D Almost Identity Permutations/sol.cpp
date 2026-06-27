#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll N=1e5+1;

ll D[5] {1,0,1,2,9};

ll C(ll n,ll k)
{
    ll ans=1;
    for(ll i=0; i<k;i++)
    {
        ans=ans*(n-i);
    }
    for(ll i=1; i<=k ;i++)
    {
        ans/=i;
    }
    return ans;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //cout<<C(4,1) * D[1]<<endl;
    ll n,k; cin>>n>>k;
    ll ans=0;
    for(ll i=0; i<=k;i++)
    {
        ans+=C(n,i) * D[i];
    }
    cout<<ans<<'\n';
}


