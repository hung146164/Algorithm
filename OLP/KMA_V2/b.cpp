#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll N=1e5+1;
const ll inf=LLONG_MAX/4;
ll maxll(ll a,ll b)
{
    if(a>b) return a;
    return b;
}
ll minll(ll a,ll b)
{
    if(a>b) return b;
    return a;
}
ll gdc(ll a, ll b)
{
    if(b==0) return a;
    return gdc(b,a%b);
}

ll result=LLONG_MAX/4;
bool check(vector<ll>& nums, ll m,ll d)
{
    //cout<<m<<endl;
    //
    priority_queue<ll,vector<ll>,greater<ll>> pq;

    ll clamp=maxll(0LL,(ll)nums.size()-m);
    //bool run=false;
    for(int i=nums.size()-1; i>=(ll)nums.size()-m; i--)
    {

        if(i>=0) pq.push(nums[i]);
        //run=true;
    }
//    if(m==1)
//    {cout<<ans[0]<<endl; cout<<run<<'\n';}
    for(ll i=0; i<clamp; i++)
    {
        ll curr= pq.top();
        pq.pop();
        pq.push(curr+nums[i]);
    }
    ll re=0;
    while(!pq.empty())
    {
        if(pq.top()>d) return false;
        re=maxll(d-pq.top(),re);
        pq.pop();
    }
    //if(m==1) cout<<ans[0]<<'\n';
    result=minll(result,re);
    return true;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,d; cin>>n>>d;
    vector<ll> nums;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;

    for(ll i=0;i<n; i++)
    {
        ll x; cin>>x;
        nums.push_back(x);

    }
    sort(nums.begin(),nums.end());

//    ll l=1,r=1e18+1;
//    while(l<=r)
//    {
//        ll m=l+(r-l)/2;
//        if(check(nums,m,d))
//        {
//            r=m-1;
//        }
//        else
//        {
//            l=m+1;
//        }
//    }
    for(int i=1; i<10000; i++)
    {
        check(nums,i,d);
    }
    if(result==inf)
    {
        cout<<"IMPOSSIBLE"<<'\n';
    }
    else cout<<result<<'\n';
    //cout<<(result==inf?"IMPOSSIBLE":result)<<'\n';
}
