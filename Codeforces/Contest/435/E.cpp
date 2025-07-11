#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll tim(vector<ll>& can, ll val)
{
    auto it=upper_bound(can.begin(),can.end(),val);
    ll ans=1e18+7;
    if(it!=can.end())
    {
        ans=min(ans,abs(val-*it));
    }
    if(it!=can.begin())
    {
        ans=min(ans,abs(val-*prev(it)));
    }
    return ans;
}
int main()
{
    ll n,m,q; cin>>n>>m>>q;
    vector<ll> n1,n2;
    for(ll i=0; i< n;i ++)
    {
        ll x; cin>>x;
        n1.push_back(x);
    }
    for(ll i=0; i< m ; i++)
    {
        ll x; cin>>x;
        n2.push_back(x);
    }

    //
    ll sum1=0,sum2=0;
    ll cc=1;
    for(ll i=0; i<n ;i++)
    {
        sum1+=cc*n1[i];
        sum2+=cc*n2[i];
        cc*=-1;
    }
//    cout<<"sum1: "<<sum1<<endl;
    vector<ll> can;
    can.push_back(sum2);
    for(ll i=n;i<m;i++)
    {
        sum2=-(sum2-n2[i-n])+(n%2==1?1:-1)*n2[i];
        can.push_back(sum2);
    }
//    cout<<"sum2 "<<endl;
    sort(can.begin(),can.end());
//    for(int i=0; i< can.size(); i++)
//    {
//        cout<<can[i]<<" ";
//    }
//    cout<<endl;
//    cout<<endl;
    cout<<tim(can,sum1)<<'\n';
    while(q--)
    {
        ll x, y,val;
        cin>>x>>y>>val;
        x--;y--;
        if((y-x)%2==0)
        {
            sum1+=(x%2==0?val:-val);
        }
        cout<<tim(can,sum1)<<'\n';
    }
}
