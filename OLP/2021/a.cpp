#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll N=1e5+1;


signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, f,d;
    cin>>n>>f>>d;
    f--;
    vector<pair<ll,ll>> nums;
    for(ll i=0; i< n; i++)
    {
        ll a,b; cin>>a>>b;
        nums.push_back({a,b});
    }

    vector<ll> f1;
    vector<ll> f2;
    vector<bool> check(n);
    check[f]=true;
    for(ll i=0; i< n; i++)
    {
        if(check[i]) continue;
        ll disx=nums[i].first-nums[f].first;
        ll disy=nums[i].second-nums[f].second;

        if(d*d>(disx*disx + disy*disy))
        {
            f1.push_back(i);
            check[i]=true;
        }
    }
    for(ll i=0; i<(ll)f1.size(); i++)
    {
        for(ll j=0; j< n; j++)
        {
            if(check[j]) continue;
            ll disx=nums[f1[i]].first-nums[j].first;
            ll disy=nums[f1[i]].second-nums[j].second;
            if(d*d>(disx*disx+disy*disy))
            {
                f2.push_back(j);
                check[j]=true;
            }
        }
    }
    cout<<(ll)f1.size()<<' '<<(ll)f2.size()<<'\n';
}


