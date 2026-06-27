#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=1e5+1;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,q; cin>>n>>q;
    vector<ll>prefix(1,0);
    for(ll i=0; i< n;i++)
    {
        ll x; cin>>x;
        prefix.push_back(x+prefix[i]);
    }
    //for(auto i: prefix) cout<<i<<' ';
    while(q--)
    {
        ll a,b; cin>>a>>b;
        cout<<prefix[b]-prefix[a-1]<<'\n';
    }

}


