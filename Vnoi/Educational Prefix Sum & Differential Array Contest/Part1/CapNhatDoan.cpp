#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    ll n,q; cin>>n>>q;
    vector<ll> prefix(n+1);
    vector<ll> nums;
    for(ll i=0; i< n;i ++)
    {
        ll x; cin>>x;
        nums.push_back(x);
    }
    while(q--)
    {
        ll a,b,c; cin>>a>>b>>c;
        a--;
        b--;
        prefix[a]+=c;
        prefix[b+1]-=c;
    }

    ll val=0;
    for(ll i=0; i< nums.size(); i++)
    {
        val+=prefix[i];
        cout<<nums[i]+val<<' ';
    }


}
