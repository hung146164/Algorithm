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

void solve()
{
    ll n,m ; cin>>n>>m;
    vector<ll> total(26);
    vector<vector<ll>> nums(n,vector<ll>(26));
    for(ll i=0; i< n; i++)
    {
        string s; cin>>s;
        for(ll j=0; j< s.size(); j++)
        {
            nums[i][s[j]-'A']++;
        }
        for(ll j=0; j< 26; j++)
        {
            total[j]+=nums[i][j]*m;
        }
    }
    //cout<<"OK"<<endl;
    for(ll i=0; i<n; i++)
    {
        ll ans=INT_MAX;
        bool isfound=true;
        for(ll j=0; j< 26; j++)
        {
            ll avai=total[j]-nums[i][j]*m;
            if(avai<nums[i][j])
            {
                isfound=false;
                break;
            }
            ll have=avai-nums[i][j];
            ll need=total[j]/m-nums[i][j];
            if(need!=0)
            {
                ans=min(ans,have/need);
            }
        }
        if(!isfound)
        {
            cout<<-1<<' ';
            continue;
        }
        cout<<(ans==INT_MAX?-1:ans)<<' ';
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









