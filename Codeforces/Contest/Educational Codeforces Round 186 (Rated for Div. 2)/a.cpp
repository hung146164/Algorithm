/*
    Author: HungForree
    Link:
*/

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
    int t; cin>>t;
    for(int i=1; i<=t; i++)
    {
        int n;
        string s;
        cin>>n>>s;
        int ans=4;
        string need="2025";
        if(s.find(need)==string::npos)
        {
            cout<<0<<el;
            continue;
        }
        for(int i=3; i<n; i++)
        {
            int val=0;
            if(s[i-3]=='2')
            {
                val++;
            }
            if(s[i-2]=='0')
            {
                val++;
            }
            if(s[i-1]=='2')
            {
                val++;
            }
            if(s[i]=='6') val++;

            ans=min(ans,4-val);
        }
        cout<<ans<<el;

    }
}




