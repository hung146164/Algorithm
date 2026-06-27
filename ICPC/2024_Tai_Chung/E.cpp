
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

void solve()
{
    int a,b; cin>>a>>b;
    if(a==b)
    {
        cout<<1<<el;
        cout<<a<<el;
        return;
    }
    cout<<3<<el;
    int sum=3*a-b;
    for(int j=b+1;j<=1000000; j++)
    {
        if(sum-j<=b)
        {
            cout<<sum-j<<' '<<b<<' '<<j<<el;
            return;
        }
    }


}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; t=1;
    while(t--)
    {
        solve();
    }
}







