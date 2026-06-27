/*
    Author: HungForree
    Link:
*/

#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
const ll N=3e5+5;
const ll mod=998244353;
const ll modr=1e9+9;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
using i128 = __int128;
constexpr i64 inf = 1E18;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
ll powll(ll a, ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a%mod;
        }
        b/=2;
        a=a*a%mod;
    }
    return ans;
}
ll gt[N],ingt[N];
void process()
{
    gt[0]=ingt[0]=1;
    for(int i=1; i<N; i++)
    {
        gt[i]=gt[i-1]*i%mod;
        ingt[i]=ingt[i-1]*powll(i,mod-2)%mod;
    }
}
ll C(ll n,ll k)
{
    if(k>n) return 0;
    return (gt[n]*ingt[k]%mod)*ingt[n-k]%mod;
}
bool cmp(pair<ll,ll>& a, pair<ll,ll>& b)
{
    return a.first<b.first;
}
void solve()
{
    process();
    ll n,k; cin>>n>>k;
    vector<pair<ll,ll>> line;
    vector<ll> clone;
    for(ll i=0; i< n; i++)
    {
        ll a, b; cin>>a>>b;
        clone.push_back(a);
        clone.push_back(b);
        line.push_back({a,b});
    }
    sort(clone.begin(),clone.end());
    clone.erase(unique(clone.begin(),clone.end()),clone.end());
    for(ll i=0; i<n; i++)
    {
        line[i].first=lower_bound(clone.begin(),clone.end(),line[i].first)-clone.begin();
        line[i].second=lower_bound(clone.begin(),clone.end(),line[i].second)-clone.begin();
    }
    sort(line.begin(),line.end(),cmp);
    ll ans=0;
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    //cout<<"Hehe"<<el;
    for(auto&[start,end]:line)
    {
        while(!pq.empty() && start>pq.top())
        {
            pq.pop();
        }
        //cout<<pq.size()<<' '<<k-1<<el;
        ans=(ans+C(pq.size(),k-1))%mod;
        pq.push(end);
    }
    cout<<ans<<el;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll t; t=1;
    while(t--)
    {
        solve();
    }
}









