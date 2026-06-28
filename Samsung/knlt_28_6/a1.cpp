#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+5;
const int mod=1e9+7;

void solve()
{
    int n; cin>>n;
    vector<vector<ll>> ans(n,vector<ll>(n));
    for(int i=0; i< n;i ++)
    {
        ans[i][0]=1;
        ans[i][i]=1;
    }

    for(int i=2;i<n; i++)
    {
        for(int j=1;j<i;j++)
        {
            ans[i][j]=ans[i-1][j]+ans[i-1][j-1];
        }
    }
    for(int i=0;i<n; i++)
    {
        for(int j=0; j<=i;j++)
        {
            cout<<ans[i][j]<<' ';
        }
        cout<<'\n';
    }

}

signed main()
{
    solve();
}









