#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(pair<ll,ll>&a,pair<ll,ll>& b)
{
    if(a.second==b.second) return a.first>b.first;
    return a.second>b.second;
}
void sol()
{
    ll n; cin>>n;
    map<ll,ll> m;
    for(ll i=0; i< n; i++)
    {
        ll x; cin>>x;
        m[x]++;
    }
    vector<pair<ll,ll>> nums;
    for(auto i: m)
    {
        nums.push_back(i);
    }
    sort(nums.begin(),nums.end(),cmp);
    bool turn=0;
    ll ans1=0,ans2=0;
    for(ll i=0; i< nums.size(); i++)
    {
        ll soluong=nums[i].first;

        ll tien=nums[i].second;
        //cout<<tien<<' '<<soluong<<'\n';
        ll a,b;
        if(soluong%2==0)
        {
            a=soluong/2;
        }
        else{
            if(turn==0)
            {
                a=soluong/2+1;
            }
            else{
                a=soluong/2;
            }
            turn =!turn;
        }
        b=soluong-a;
        ans1+=a*tien;
        ans2+=b*tien;
    }
    cout<<ans1<<' '<<ans2<<'\n';

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin>>t;
    while(t--)
    {
        sol();
    }

}

