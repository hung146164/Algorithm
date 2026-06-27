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
void longestValidParentheses(string& s) {
    stack<pair<char,int>> st;
    int n=s.size();
    vector<bool> check(n);
    for(int i=0; i< s.size(); i++)
    {
        if(!st.empty() && s[i]==')' && st.top().first=='(')
        {
            check[st.top().second]=true;
            check[i]=true;
            st.pop();
        }
        else
        {
            st.push({s[i],i});
        }
    }
    int max_val=0;
    int k=1;
    for(int i=1; i<n;i++)
    {
        if(check[i]&&check[i-1])
        {
            k++;
        }
        else
        {
            k=1;
        }
        max_val=max(max_val,k/2*2);
    }
    if(max_val==0)
    {
        cout<<max_val<<' '<<1<<el;
        return;
    }
    //for(int i=0; i<check.size(); i++) cout<<check[i]<<' ';
    int cnt=0;
    for(int i=0; i<max_val;i++)
    {
        if(check[i]) cnt++;
    }
    int ans=0;
    if(cnt==max_val) ans++;
    for(int r=max_val;r<n; r++)
    {
        if(check[r-max_val]) cnt--;
        if(check[r]) cnt++;
        if(cnt==max_val) ans++;
    }
    cout<<max_val<<' '<<ans<<el;
}
void solve()
{
    string s; cin>>s;
    longestValidParentheses(s);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int t; t=1;
    while(t--)
    {
        solve();
    }
}









