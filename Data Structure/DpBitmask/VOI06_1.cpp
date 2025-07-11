#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e4+1;
ll dp[16][N],nums[4][N];
bool valid[16];

vector<ll> getindexbit(ll n, ll numbit)
{
    vector<ll> ans;
    for(ll i=0; i<numbit;i++)
    {
        if(n&1) ans.push_back(i);
        n>>=1;
    }
    return ans;
}
ll getbit(ll n,ll index)
{
    return (n>>index)&1;
}
void process()
{
    for(ll i=0; i< 16; i++)
    {
        bool ok=true;
        for(ll j=0; j< 3; j++)
        {
            if(getbit(i,j) && getbit(i,j+1)) ok=false;
        }
        valid[i]=ok;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin>>n;
    ll ans=INT_MIN;
    process();
    for(ll i=0; i<4; i++)
    {
        for(ll j=1; j<= n ; j++)
        {
            cin>>nums[i][j];
            ans=max(ans,nums[i][j]);
        }
    }
    if(ans<0)
      {
          cout<<ans<<'\n';
        return 0;
      }
    for(ll j=1; j<=n; j++)
    {
        for(ll i=0; i<16; i++)
        {
            if(valid[i])
            {
                //handle sum
                ll sum=0;
                vector<ll> ib= getindexbit(i,4);
                for(auto k: ib)
                {
                    sum+=nums[k][j];
                }
                ll ma=sum;
                for(ll k=0; k<16; k++)
                {
                    if(valid[k] && ((i&k)==0) )
                    {
                        ma=max(ma,sum+dp[k][j-1]);
                    }
                }
                dp[i][j]=ma;
                ans=max(ans,ma);
            }

        }
    }
    cout<<ans<<'\n';

}
