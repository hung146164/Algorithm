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
const ll N=1005;
const ll mod=1e9+7;
const ll modr=1e9+9;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
using i128 = __int128;
constexpr i64 inf = 1E18;

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
bool check[N];
vector<int> sang(int n)
{
    vector<int> ans;
    for(int i=2; i<=n; i++)
    {
        if(!check[i])
        {
            ans.push_back(i);
            for(int j=i*i; j<=n; j+=i)
            {
                check[j]=true;
            }
        }
    }
    return ans;
}
void solve()
{
    int n, k;
    cin>>n>>k;
    vector<int> snt=sang(n);
    int cnt=0;
    for(int i=0; i< snt.size()-1; i++)
    {

        int need=(snt[i]+snt[i+1]+1);
        auto it=lower_bound(snt.begin(),snt.end(),need);
        if(it!=snt.end() && *it==need)
        {
            cnt++;

        }

    }
    cout<<(cnt>=k?"YES":"NO")<<el;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int t;
    t=1;
    while(t--)
    {
        solve();
    }
}









