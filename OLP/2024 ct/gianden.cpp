#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll N=1e5+1;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,k; cin>>n>>k;
    if(k==0)
    {
        if(n==1)
        {
            cout<<0<<'\n';
            return 0;
        }
        ll ans=0;
        ll c=2;
        for(ll i=0; i<n-1; i++)
        {
            ll start=1;
            for(ll j=i;j<n-1; j++)
            {
                ans+=start;
                start+=c;
            }
            c++;
        }
        cout<<ans<<'\n';

    }
}


