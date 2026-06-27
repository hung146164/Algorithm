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
int nums[N];
void solve()
{
    ll x; cin>>x;

    ll cnt=0;
    vector<pair<ll,bool>> val;
    string s=to_string(x);
    val.push_back({s[0]-'0'-1,false});
    cnt+=s[0]-'0';
    for(int i=1; i< s.size(); i++)
    {
        val.push_back({s[i]-'0',false});
        cnt+=s[i]-'0';
    }
   // cout<<cnt<<el;
    if(cnt<10)
    {
        cout<<0<<el;
    }
    else{
        ll ans=0;
        sort(val.begin(),val.end(),greater<pair<ll,bool>>());
        for(ll i=0; i<val.size(); i++)
        {
            if(cnt>9)
            {
                if(val[i].first > 0)
                    {
                        cnt-=val[i].first;
                        ans++;
                    }

            }
            else break;
        }
        cout<<ans<<el;
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll t; cin>>t;
    while(t--)
    {
        solve();
    }
}










