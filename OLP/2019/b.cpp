#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const ll N=1e5+1;

vector<vector<ll>> mul(vector<vector<ll>>& a, vector<vector<ll>>& b)
{
    ll n=a.size();
    ll m=b.size();
    vector<vector<ll>> ans(n,vector<ll>(m));
    for(ll i=0; i< n; i++)
    {
        for(ll j=0; j< m ;j++)
        {
            for(ll k=0; k< n; k++)
            {
                ans[i][j]=(ans[i][j]+a[i][k]*b[k][j]%mod)%mod;
            }
        }
    }
    return ans;
}
vector<vector<ll>> power(vector<vector<ll>>& a, ll b, vector<vector<ll>>& dv)
{
    vector<vector<ll>> ans=dv;
    while(b)
    {
        if(b&1)
        {
            ans=mul(ans,a);
        }
        b/=2;
        a=mul(a,a);
    }
    return ans;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin>>n;
    vector<vector<ll>> base {{0,1},{1,1}};
    vector<vector<ll>> dv({{1,0},{0,1}});

    vector<vector<ll>> start{{1,1}};

    vector<vector<ll>> clone = power(base,n+2,dv);

    vector<vector<ll>> ans= mul(start,clone);

    cout<<ans[0][0]*ans[0][1]%mod<<'\n';

}
