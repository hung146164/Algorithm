#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+1,step=32;
int dp[N][step];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin>>n>>q;
    for(int i=1; i<= n; i++)
    {
        cin>>dp[i][0];
    }

    for(int j=1; j<step; j++)
    {
        for(ll i=1; i<=n; i++)
        {
            dp[i][j]=dp[dp[i][j-1]][j-1];
        }
    }

    while(q--)
    {
        int x;
        cin>>x;
        long long k ;
        cin>>k;
        for(int j=0; j< 32; j++)
        {
            if(k&(1LL<<j))
            {
                x=dp[x][j];
            }
        }
        cout<<x<<'\n';
    }
}
