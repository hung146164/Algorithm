#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
const ll N=5e5+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int n; cin>>n;
    vector<vector<int>> dp(n+1,vector<int>(n+1));
    for(int i=1; i<= n; i++)
    {
        for(int j=1; j<=n-i+1; j++)
        {
            cin>>dp[i][j];
        }
    }
    for(int i=1; i<= n; i++)
    {
        if(dp[1][i]>dp[1][i-1]) cout<<i<<' ';
    }
    cout<<el;
}

