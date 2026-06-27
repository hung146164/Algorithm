#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   ll n,m;cin>>n>>m;
   vector<vector<ll>> prefix(n+1,vector<ll>(m+1));
   for(ll i=1;i<=n; i++)
   {
       for(ll j=1; j<=m; j++)
       {
           ll x; cin>>x;
           prefix[i][j]=prefix[i-1][j]+x;
       }
   }

   ll ans=INT_MIN;
   for(ll top=1;top<=n;top++)
   {
       for(ll bot=n;bot>=top;bot--)
       {
            ll pre=prefix[bot][1]-prefix[top-1][1];
            for(ll left=2;left<=m ;left++)
            {
                ll can=prefix[bot][left]-prefix[top-1][left];
                pre=max(pre+can,can);
                ans=max(ans,pre);
            }
       }
   }
   cout<<ans<<'\n';
}
