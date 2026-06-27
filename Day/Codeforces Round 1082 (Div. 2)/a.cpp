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

int a,b;
bool sol(int x,int y)
{
    if(x==a && y==b)
    {
        return true;
    }
    if(x>a) return false;
    if(y==b)
    {
        return sol(x+2,y+1)|sol(x+4,y-1)|sol(x+3,y);
    }
    else if(y>b)
    {
        return sol(x+4,y-1);
    }
    else
    {
        return sol(x+2,y+1);
    }
}
void solve()
{
    cin>>a>>b;
    int x=0;
    int y=b;
    if(b>0) x=2*b;
    else x=-4*b;
    if(x>a)
    {
        cout<<"NO"<<el;
        return;
    }
    if(abs(a-x)%6==0 || abs(a-x)%3==0)
    {
        cout<<"YES"<<el;
    }
    else
    {
        cout<<"NO"<<el;
    }
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









