#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t; cin>>t;
    while(t--)
    {
        ll n,m; cin>>n>>m;
        if(m<n || n*(n+1)/2 <m)
        {
            cout<<-1<<'\n';
            continue;
        }
        ll pi=n;
        vector<bool> ans(n+1,false);
vector<ll> cc;
        for(ll i=n;i>0; i--)
        {
           if(m-i>=pi-1)
           {
               m-=i;
               cc.push_back(i);
               pi--;
               ans[i]=true;
           }
        }

        for(ll i=1; i< ans.size(); i++)
        {
            if(!ans[i]) cc.push_back(i);
        }
        cout<<cc[0]<<'\n';
        for(ll i=0; i< cc.size()-1; i++)
        {
            cout<<cc[i]<<' '<<cc[i+1]<<'\n';
        }
    }
}
