#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin>>n;
    ll ans=INT_MIN,pre=INT_MIN;
    for(ll i=0; i< n;i ++)
    {
        ll x; cin>>x;
        pre=max(pre+x,x);
        ans=max(ans,pre);
    }
    cout<<ans<<'\n';
}
