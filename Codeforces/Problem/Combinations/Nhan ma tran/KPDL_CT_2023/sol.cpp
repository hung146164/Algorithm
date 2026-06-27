#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll N=100001;
ll n,k;
ll dp[N][3][101][3];
void reset()
{
    for(ll i=0; i< N; i++)
    {
        for(ll j=0; j< 3; j++)
        {
            for(ll ii=0; ii<101; ii++)
            {
                for(ll jj=0;jj<3; jj++)
                {
                    dp[i][j][ii][jj]=-1;
                }
            }
        }
    }
}
ll sol(ll x,ll y,ll val,ll gtcot)
{
   // cout<<x<<' '<<y<<' '<<val<<' '<<gtcot<<'\n';
    ll ans=0;
    if(x>=n)
    {
        if(val==0)
        {
            return 1;
        }
        return 0;
    }
    if(dp[x][y][val][gtcot]!=-1) return dp[x][y][val][gtcot];
    if(y<2)
    {
        if(gtcot<2) ans=(ans+sol(x,y+1,(val+1)%k,gtcot+1))%mod;
        ans=(ans+sol(x,y+1,val,gtcot))%mod;
    }
    else{
        if(gtcot<2) ans+=(sol(x+1,0,(val+1)%k,0))%mod;
        ans=(ans+sol(x+1,0,val,0))%mod;
    }

    return dp[x][y][val][gtcot]=ans;

}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    reset();
    cin>>n>>k;

    cout<<sol(0,0,0,0)-1<<'\n';
}


