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
const ll N=1e6+5;
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

int nums[N];
void solve()
{
    int n,k; cin>>n>>k;
    ll ans=0;
    int minn=INT_MAX;
    int pos=-1;
    for(int i=0; i< n; i++)
    {
        int x; cin>>x;
        ans+=x;
        nums[i]=x;
        int cnt=0;
        while(x%k==0)
        {
            x/=k;
            cnt++;
        }
        if(cnt<minn)
        {
            minn=cnt;
            pos=i;
        }
    }
    if(minn!=INT_MAX)
    {
        for(int i=0; i< n; i++)
        {
            int cnt=1;
            for(int j=0;j<minn;j++)
            {
                nums[i]/=k;
                cnt*=k;
                ans+=nums[i]*cnt;
            }
            if(i<pos)
            {
                nums[i]/=k;
                cnt*=k;
                ans+=nums[i]*cnt;
            }
        }
    }
    cout<<ans<<'\n';
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int t;t=1;
    while(t--)
    {
        solve();
    }
}










