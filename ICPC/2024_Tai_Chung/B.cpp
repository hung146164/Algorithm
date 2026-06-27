#include<bits/stdc++.h>
using namespace std;
#define el '\n';
typedef long long ll;

void solve()
{
    ll a, b; cin>>a>>b;
    ll sum=a+b;
    ll ans=0;
    for(ll i=1;i<1000000;i++)
    {
        if(i*(i+1)/2>sum)
        {
            ans=i-1;
            break;
        }
    }
    cout<<ans<<el;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin>>t;
    while(t--)
    {
        solve();
    }
}