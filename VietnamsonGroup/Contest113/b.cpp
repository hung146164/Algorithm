#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+5;
const int mod=1e9+7;

void solve()
{
    int n ; cin>>n;
    vector<int> a(n);
    for(int i=0; i< n; i++) cin>>a[i];
    sort(a.begin(),a.end());
    if(a[0]!=1)
    {
        cout<<"NO"<<'\n';
        return;
    }
    int sum=1;
    for(int i=1;i<n; i++)
    {
        if(sum<a[i])
        {
            cout<<"NO"<<'\n';
            return;
        }
        sum+=a[i];
    }
    cout<<"YES"<<'\n';
}

signed main()
{

    int t; cin>>t;
    while(t--)
    {

    solve();

    }
}









