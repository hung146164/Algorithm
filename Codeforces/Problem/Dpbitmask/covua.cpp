#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll N=1e5+1;

ll n,k;
ll dp[5][5][5*5][2<<5][2<<5];

ll sol(ll x,ll y, ll v, ll premask,ll currentmask)
{

    if(v==0)
    {
        return 1;
    }
    if(x==n) return 0;
    if(dp[x][y][v][premask][currentmask]!=-1) return dp[x][y][v][premask][currentmask];
    ll ans=0;
    if(!((premask>>y &1) || (premask>>(y-1) &1) || (premask>>(y+1)&1)))
    {
        if(y+2>=n)
        {
            ll he=sol(x+1,0,v-1,currentmask|(1<<y),0);
            ans+=he;

        }
        else{
            ans+=sol(x,y+2,v-1,premask,currentmask|(1<<y));
        }

    }
    if(y+1>=n)
    {
        ll he=sol(x+1,0,v,currentmask,0);
        ans+=he;

    }
    else ans+=sol(x,y+1,v,premask,currentmask);
    return dp[x][y][v][premask][currentmask]=ans;

}
void reset()
{
    for(ll i=0; i< 5; i++)
    {
        for(ll j=0; j< 5; j++)
        {
            for(ll k=0; k<5*5; k++)
            {
                for(ll ii=0; ii<(2<<5); ii++)
                {
                    for(ll jj=0; jj<(2<<5); jj++)
                    {
                        dp[i][j][k][ii][jj]=-1;
                    }
                }
            }
        }
    }
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>k;
    reset();
    cout<<sol(0,0,k,0,0)<<'\n';
}


