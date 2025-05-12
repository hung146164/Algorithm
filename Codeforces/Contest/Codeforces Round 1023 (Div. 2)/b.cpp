#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void)
{
    ll t;cin>>t;
    while(t--)
    {
        ll n,k;cin>>n>>k;
        ll maxx=LLONG_MIN;
        ll minn=LLONG_MAX;
        ll sum=0;
        vector<ll> dp;
        for(int i=0; i< n; i++)
        {
            ll x; cin>>x;
            dp.push_back(x);
            sum+=x;
            minn=min(minn,x);
            maxx=max(maxx,x);
        }
        ll count=0;
        for(int i=0; i< n; i++)
        {
            if(dp[i]==maxx) count++;
        }
        //if over lose and have do
        if ((maxx - minn > k+1) || (maxx-minn==k+1 && count>1)) {
            cout << "Jerry"<<endl;
        }
        else
        {
            if(sum%2) cout<<"Tom"<<endl;
            else cout<<"Jerry"<<endl;
        }
    }
}
