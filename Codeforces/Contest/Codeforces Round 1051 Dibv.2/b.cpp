#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sol()
{
    ll n,x; cin>>n>>x;
    vector<ll> nums,p;
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    for(ll i=0; i< n; i++)
    {
        ll c; cin>>c;
        nums.push_back(c);

    }
    for(ll i=0; i< x; i++)
    {
        ll c; cin>>c;
        p.push_back(c);
        pq.push(c);
    }
    sort(nums.begin(),nums.end());
    sort(p.begin(),p.end());
    ll cu=n-1;
    ll ans=0;
    while(!pq.empty())
    {
        ll curr=pq.top();
        pq.pop();
        if(curr==1)
        {
            cu--;
            continue;
        }
        if(curr<=cu+1)
        {
            ll en= cu-(curr-1);
            for(;cu>en;cu--)
            {
                ans+=nums[cu];
            }
            cu--;
        }
        else
        {
            for(;cu>=0;cu--) ans+=nums[cu];
        }
    }
    while(cu>=0) {ans+=nums[cu]; cu--;}
    return ans;


}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--)
    {
        cout<<sol()<<'\n';
    }
}

