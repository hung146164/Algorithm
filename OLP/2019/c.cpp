#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll N=1e5+1;

ll maxll(ll a,ll b)
{
    if(a>b) return a;
    return b;
}
ll minll(ll a,ll b)
{
    if(a>b) return b;
    return a;
}
ll gdc(ll a, ll b)
{
    if(b==0) return a;
    return gdc(b,a%b);
}

namespace sub1
{
bool CheckSub1()
{
    return true;
}
void sol()
{

}
}
namespace sub2
{
bool CheckSub2()
{
    return true;
}
void sol()
{

}
}
namespace sub3
{
bool CheckSub3()
{
    return true;
}
void sol()
{

}
}
ll red;
ll sol(vector<vector<ll>>& nums)
{
    ll x1,y1,x2,y2,c;
    cin>>c>>y1>>x1>>y2>>x2;
    x1--;
    y1--;
    x2--;
    y2--;
    ll ans=0;
    for(ll i=x1; i<=x2; i++)
    {
        if((i-x1)%2==0)
        {
            for(ll j=y1; j<=y2; j++)
            {
                if(nums[i][j]>=red)
                {
                    ll add= min({nums[i][j]-red,c});
                    ans+=add;
                    nums[i][j]-=add;
                    c-=add;
                }
                else return 0;
            }
        }
        else
        {
            for(ll j=y2; j>=y1; j--)
            {
                if(nums[i][j]>=red)
                {
                    ll add= min({nums[i][j]-red,c});
                    ans+=add;
                    nums[i][j]-=add;
                    c-=add;
                }
                else return 0;
            }
        }
    }
    return ans;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> nums(n,vector<ll>(m));
    for(ll i=0; i< n; i++)
    {
        for(ll j=0; j< m; j++)
        {
            cin>>nums[i][j];
        }
    }
    ll t;
    cin>>t;

    cin>>red;
    while(t--)
    {
        ll type;
        cin>>type;
        if(type==2)
        {
            cin>>red;
        }
        else
        {
            cout<<sol(nums)<<'\n';
        }
    }
}

