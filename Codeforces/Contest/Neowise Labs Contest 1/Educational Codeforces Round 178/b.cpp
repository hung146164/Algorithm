#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;cin>>t;
     while (t--)
    {
        ll n; cin>>n;
        vector<ll> dp;
        vector<ll> maxx;
        for(int i=0; i< n; i++)
        {
            ll x; cin>>x;
             dp.push_back(x);
             if(i==0) maxx.push_back(x);
             else
             {
                 maxx.push_back(max(maxx[i-1],x));
             }
        }
        vector<ll> prefix;
        prefix.push_back(0);
        ll sum=0;
        for(int i=dp.size()-1; i>=0; i--)
        {
            sum+=dp[i];
            prefix.push_back(sum);
        }
        vector<ll> ans;
        reverse(prefix.begin(),prefix.end());
//        for(auto i: prefix) cout<<i<<" ";
//        cout<<endl;
//        for(auto i: maxx) cout<<i<<" ";
        for(int i=maxx.size()-1; i>=0; i--)
        {
            ans.push_back(maxx[i]+prefix[i+1]);
        }
        for(auto i: ans) cout<<i<<" ";
        cout<<endl;
    }
}
