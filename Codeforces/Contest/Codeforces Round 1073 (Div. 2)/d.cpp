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
    int n; cin>>n;
    string s; cin>>s;
    vector<int> p;
    for(int i=0; i< s.size(); i++)
    {
        if(s[i]=='(') p.push_back(i);
    }
    for (int i = 0; i < n - 2; ++i) {
        if (s[i]== ')'&& s[i+1]=='(') {
            if(upper_bound(p.begin(),p.end(),i+1)!=p.end())

            {
                cout<<n-2<<el;
            return;
            }

        }
    }
    cout<<-1<<el;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--)
    {
        solve();
    }
}








