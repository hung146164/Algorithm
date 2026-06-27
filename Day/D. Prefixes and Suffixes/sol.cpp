/*
    Author: HungForree
    Link: https://codeforces.com/problemset/problem/432/D
*/
// kỹ thuật đếm to về nhỏ
#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
const ll N=1e5+5;
const ll mod=1e9+7;
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
ll pow31[N],in31[N];
ll powll(ll a, ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a%mod;
        }
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
void process()
{
    pow31[0]=in31[0]=1;
    ll i31=powll(31,mod-2);
    for(ll i=1; i<N; i++)
    {
        pow31[i]=pow31[i-1]*31%mod;
        in31[i]=in31[i-1]*i31%mod;
    }
}
struct hashing
{
    public:
    vector<ll> h;
    hashing(string& s)
    {
        ll n=s.size();
        h.resize(n+1);
        for(ll i=0;i< n; i++)
        {
            h[i+1]=(h[i]+(s[i]-'A'+1)*pow31[i])%mod;
        }
    }
    ll get(ll a, ll b)
    {
        return ((h[b]-h[a-1]+mod)%mod)*in31[a-1]%mod;
    }
};
void solve()
{
    process();
    string s; cin>>s;
    hashing h= hashing(s);
    int n=s.size();
    vector<int> pos,val(n+1);
    for(ll i=1;i<=n; i++)
    {
        if(h.get(1,i)==h.get(n-i+1,n))
        {
            pos.push_back(i);
        }
    }

    for(int i=1; i<=n;i++)
    {
        int l=1,r=n-i+1;
        int ans=0;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(h.get(1,m)==h.get(i,i+m-1))
            {
                ans=m;
                l=m+1;
            }
            else
            {
                r=m-1;
            }
        }
        if(ans!=0 && ans!=n+1)
        {
            val[ans]++;
        }
    }
    for(int i=(int)val.size()-2; i>=0; i--)
    {
        val[i]+=val[i+1];
    }
    cout<<pos.size()<<el;
    for(int i=0; i< pos.size(); i++)
    {
        cout<<pos[i]<<' '<<val[pos[i]]<<el;
    }

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










