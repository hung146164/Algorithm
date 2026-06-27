#include<bits/stdc++.h>
#define ll long long
#define en "\n"
using namespace std;
const ll mod=1e9+7;
const ll modb=1e9+9;

const ll N=2e3+1;
ll ha[N];
ll pow31[N];
ll in31[N];

ll hac[N];
ll pow31a[N];
ll in31a[N];

ll powll(ll a, ll b, ll m)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a%m;
        }
        b/=2;
        a=a*a%m;
    }
    return ans;
}
void process()
{
    pow31[0]=pow31a[0]=1;
    in31[0]=in31a[0]=1;

    ll i31=powll(31,mod-2,mod);
    ll i31a=powll(31,modb-2,modb);
    //cout<<i31<<' '<<i31a<<en;
    for(ll i=1; i<N; i++)
    {
        pow31[i]=pow31[i-1]*31%mod;
        pow31a[i]=pow31a[i-1]*31%modb;
        in31[i]=in31[i-1]*i31%mod;
        in31a[i]=in31a[i-1]*i31a%modb;
    }
}
ll get(ll a, ll b)
{
    return (((ha[b]-ha[a-1])%mod+mod)%mod)* in31[a-1] %mod;
}
ll get2(ll a, ll b)
{
    return (((hac[b]-hac[a-1])%modb+modb)%modb)* in31a[a-1] %modb;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//   freopen("output.txt","w",stdout);
    process();
    string s;
    cin>>s;
    vector<ll> point(26);
    string clone;
    cin>>clone;
    ll k;
    cin>>k;

    for(ll i=0; i< clone.size(); i++)
    {
        point[i]=((clone[i]-'0')+1)%2;
    }

    vector<vector<ll>> fixchar(s.size()+1,vector<ll>(26));
    for(ll i=0; i< s.size(); i++)
    {
        ll val=s[i]-'a'+1;
        ha[i+1]=(ha[i]+pow31[i]*val%mod)%mod;
        hac[i+1]=(hac[i]+pow31a[i]*val%modb)%modb;
        for(ll j=0; j< 26; j++)
        {
            fixchar[i+1][j]=fixchar[i][j]+(j+1==val?1:0);
        }
    }
//    for(int j=0; j< 26; j++)
//        {
//    for(int i=0; i<= s.size(); i++)
//    {
//
//
//        cout<<fixchar[i][j]<<' ';
//        }
//        cout<<en;
//    }

//    for(int i=0; i< 20 ;i++)
//    {
//        cout<<ha[i]<<' ';
//    }
//    cout<<en;
//    for(int i=0; i< 20 ;i++)
//    {
//        cout<<hac[i]<<' ';
//    }
//    cout<<en;
//    for(int i=0; i< 20 ;i++)
//    {
//        cout<<in31[i]<<' ';
//    }
//    cout<<en;
//    for(int i=0; i< 20 ;i++)
//    {
//        cout<<in31a[i]<<' ';
//    }
//    cout<<en;
//    cout<<en;
    ll n=s.size();
    ll ans=0;

    for(ll i=1; i<=n; i++)
    {
        map<pair<int,int>,int> dp;
        for(ll j=1; j<= n-i+1; j++)
        {
            ll one=0;
            for(ll index=0; index<26; index++)
            {
                one+=(fixchar[i+j-1][index]-fixchar[j-1][index])*point[index];
            }

            if(one>k) continue;
            //cout<<i<<' '<<j<<' '<<one<<' '<<get(j,i+j-1)<<en;
            int a1=get(j,i+j-1);
            int a2= get2(j,i+j-1);
            if(dp.find({a1,a2})==dp.end())
            {
                ans++;
                dp[{a1,a2}]++;
            }
        }
    }
    cout<<ans<<en;

}
