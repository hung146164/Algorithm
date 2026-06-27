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
bool ok(string& s)
{
    for(int i=1; i< s.size(); i++)
    {
        if(s[i]=='0' && s[i-1]=='1') return false;
    }
    return true;
}
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    if( s.size()==1 || ok(s))
    {
        cout<<"Bob"<<el;
        return;
    }
    int cnt0 = 0;
    for(int i=0; i< s.size(); i++)
    {
        if(s[i]=='0') cnt0++;
    }
    cout<<"Alice"<<el;
    vector<int> ans;
    for(int i=0; i< n; i++)
    {
        if(i< cnt0)
        {
            if(s[i] == '1') ans.push_back(i);
        }
        else
        {
            if(s[i] == '0') ans.push_back(i);
        }
    }
    cout<<ans.size()<<el;
    for(int i=0; i< ans.size(); i++)
    {
        cout<<ans[i]+1<<' ';
    }
    cout<<el;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}








