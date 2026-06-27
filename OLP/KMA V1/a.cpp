#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=1e5+1;

ll sol()
{
    ll n; cin>>n;
    ll ans=0;
    for(ll i=1; i*i<=n;i++)
    {
        if(n%i==0)
        {
            ans++;
            if(n/i!=i) ans++;
        }

    }
    return ans;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout<<sol()<<'\n';
}
