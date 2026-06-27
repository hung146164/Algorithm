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
const ll N=5e5+5;
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

int st[20][N];
int nums[N];
int n;
void build()
{
    for(int i=0;i<n; i++)
    {
        st[0][i]=nums[i];
    }
    for(int j=1; j<20 ;j++)
    {
        for(int i=0; i+(1<<j) <= n; i++)
        {
            st[j][i]=min(st[j-1][i],st[j-1][i+(1<<(j-1))]);
        }
    }
}
int query(int l, int r)
{
    int len=__lg(r-l+1);
    return min(st[len][l],st[len][r-(1<<len)+1]);
}

int MAX[N];
void solve()
{
    cin>>n;
    for(int i=0; i< n;i++)
    {
        cin>>nums[i];
    }
    build();
    int maxx=0;
    for(int i=0; i< n;i++)
    {
        maxx=max(maxx,nums[i]);
        MAX[i]=maxx;
    }
    maxx=0;
    for(int i=n-1; i>=2; i--)
    {
        maxx=max(maxx,nums[i]);
        int range=i-1;
        auto it= lower_bound(MAX,MAX+range,maxx);
        if(it-MAX<range && *it==maxx)
        {
            if(query(it-MAX+1,i-1)==maxx)
            {
                cout<<"YES"<<el;
                cout<<it-MAX+1<<' '<<i-1-(it-MAX+1)+1<<' '<<n-1-i+1<<el;
                return;
            }
        }
        auto it2 = upper_bound(MAX, MAX+range, maxx);
        it2--;
        if(it2-MAX >= 0 && it2-MAX < range && *it2 == maxx)
        {
             if(query(it2-MAX+1,i-1)==maxx)
            {
                cout<<"YES"<<el;
                cout<<it2-MAX+1<<' '<<i-1-(it2-MAX+1)+1<<' '<<n-1-i+1<<el;
                return;
            }
        }
    }
    cout<<"NO"<<el;

}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int t; cin>>t;
    while(t--)
    {
        solve();
    }
}









