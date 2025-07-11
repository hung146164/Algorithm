#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll combination(ll n, ll k)
{
    if (k < 0 || k > n) {
        return 0;
    }
    if (k == 0 || k == n) {
        return 1;
    }
    if (k > n / 2) {
        k = n - k;
    }
    ll ans=1;
    for(ll i=1; i<=k; i++)
    {
        ans=ans*(n-i+1)/i;
    }
    return ans;
}
int main()
{
    ll n; cin>>n;
    for(ll i=0; i< n; i++)
    {
        ll n,k; cin>>n>>k;
        cout<<combination(n-1,k-1)<<'\n';
    }
}
