#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+5;
const int mod=1e9+7;

void solve()
{
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i< n; i++)
    {
        cin>>a[i];
    }
    int q; cin>>q;
    vector<int> p(n+1);
    while(q--)
    {
        int a, b; cin>>a>>b;
        p[a]++;
        p[b+1]--;
    }
    p.pop_back();
    for(int i=1; i<n; i++)
    {
        p[i]+=p[i-1];
    }
    sort(p.begin(),p.end());
    sort(a.begin(),a.end());
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        ans=(ans+1LL*a[i]*p[i])%mod;
    }
    cout<<ans<<'\n';
}

signed main()
{
    solve();
}









