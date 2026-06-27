#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define en '\n';

const ll mod=1e9+7;
const ll N=1e5+1;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll t; cin>>t;
    while(t--)
    {
        ll n,a,b; cin>>n>>a>>b;
        string s; cin>>s;
        ll one=0,zero=0;
        for(ll i=0; i< s.size(); i++)
        {
            if(s[i]=='0') zero++;
            else one++;
        }
//        cout<<one<<' '<<zero<<en;
        set<ll> candidate;
        for(ll i=a; i<=b; i++)
        {
            map<pair<ll,ll>,ll> check;
            ll cloneone=one;
            ll clonezero=zero;
            while(check.find({cloneone,clonezero})==check.end())
            {
                check[{cloneone,clonezero}]++;
                candidate.insert(clonezero);
                cloneone=cloneone-i;
                cloneone%=n;
                clonezero=n-(abs(cloneone));
            }
        }
//        for(auto j: candidate) cout<<j<<' ';
//        cout<<'\n';
        bool haveans=false;
        for(ll i=a;i<=b; i++)
        {
            for(auto j : candidate)
            {
                if(j%i==0)
                {
                    haveans=true;
                    break;
                }
            }
        }
        if(!haveans)
        {
            cout<<"NO"<<en;
        }
        else cout<<"YES"<<en;

    }
}
