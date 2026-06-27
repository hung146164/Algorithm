#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+5;
const int mod=1e9+7;

void solve()
{
    int cnt=0;
    int xorr=0;
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n; i++)
    {
        cin>>a[i];
        if(a[i]>0) cnt++;
        xorr^=a[i];
    }
    if(cnt<=1)
    {
        cout<<0<<'\n';
        return;
    }
    if(xorr==0)
    {
        cout<<1<<'\n';
        return;
    }
    int maxx=0;
    for(int i=29;i>=0;i--)
    {
        if((xorr>>i)&1)
        {
            maxx=i;
            break;
        }
    }
    int ans=0;
    for(int i=0; i< n; i++)
    {
        if( (a[i]>>maxx) &1) ans++;
    }
    cout<<ans<<'\n';

}

signed main()
{
    int t; cin>>t;
    while(t--)
    {
    solve();

    }
}









