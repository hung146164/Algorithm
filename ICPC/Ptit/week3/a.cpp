#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
const ll N=5e5+5;
const ll mod=1e9+7;
const ll modr=1e9+9;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll base=rng() % 500 +300;
ll powll(ll a, ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a%mod;
        }
        a=a*a%mod;
        b/=2;
    }
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int k, s; cin>>k>>s;
    int ans=0;
    vector<int> dp(s+1);
    dp[0]=1;
    set<tuple<int,int,int>> se;
    for(int i=0; i<=k; i++)
    {
        for(int j=0; j<= k; j++)
        {
            if(s-i-j<=k && s-i-j>=0) se.insert({i,j,s-i-j});
        }
    }
//    for(auto i: se)
//    {
//        cout<<get<0>(i)<<' '<<get<1>(i)<<' '<<get<2>(i)<<el;
//    }
    cout<<se.size()<<el;

}


