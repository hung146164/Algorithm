/*
    Author: HungForree
    Link:
*/
/*
    Kien thuc hoc duoc, lay tat ca uoc nguyen to cua mot mang bang mang SPF
*/
#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
const ll N=1e7+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
using i128 = __int128;
constexpr i64 inf = 1E18;
int spf[N];
void sang()
{
    for(ll i=2;i <N; i++)
    {
        if(spf[i]==0)
        {
            for(ll j=i;j<N; j+=i)
            {
                if(spf[j]==0)
                {
                    spf[j]=i;
                }
            }
        }
    }
}
void solve()
{
    sang();
    ll n; cin>>n;
    vector<ll> nums(n);
    for(ll i=0; i< n; i++)
    {
        cin>>nums[i];
    }
    vector<ll> ans(N);
    for(ll i=0; i< nums.size(); i++)
    {
        while(nums[i]>1)
        {
            ll p=spf[nums[i]];
            //cout<<nums[i]<<' '<<p<<endl;
            ans[p]++;
            while(nums[i]%p==0)
            {
                nums[i]/=p;
            }
        }
    }
    for(ll i=1; i< N; i++)
    {
        ans[i]+=ans[i-1];
    }
//    for(int i=1; i<=10;i++)
//    {
//        cout<<ans[i]<<' ';
//    }
//    cout<<el;
    ll q; cin>>q;
    for(ll i=0; i< q; i++)
    {
        ll a, b; cin>>a>>b;
        b=min(b,N-1);
        a=min(a,N-1);
        cout<<ans[b]-ans[a-1]<<el;
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









