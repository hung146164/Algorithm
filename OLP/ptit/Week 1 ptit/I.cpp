#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k;
    while(cin>>n>>k)
    {
        if(n==0)
        {cout<<0<<'\n';
        continue;
        }
        //cout<<"ha"<<endl;
        //cin>>n>>k;
        unordered_map<ll,ll> m;
        for(ll i=n-k+1; i<=n ;i++)
        {
            ll clone=i;
            for(ll j=2; j*j <= clone ;j++)
            {
                while(clone%j==0)
                {
                    m[j]++;
                    clone/=j;
                }
            }
            if(clone!=1) m[clone]++;
        }

        for(ll i=1; i<=k ;i++)
        {
            ll clone=i;
            for(ll j=2; j*j <= clone ;j++)
            {
                while(clone%j==0)
                {
                    m[j]--;
                    //if(m[j]==0) m.erase(j);
                    clone/=j;
                }
            }
            if(clone!=1) m[clone]--;
            //if(m[clone]==0) m.erase(clone);
        }
        ll ans=1;
        for(auto i: m)
        {
            ans*=(i.second+1);
        }
        cout<<ans<<'\n';

    }
}

