/*
    Author: HungForree
    Link: https://codeforces.com/problemset/problem/631/C
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
    int n,m; cin>>n>>m;
    vector<int> nums(n);
    for(int i=0; i< n; i++)
    {
        cin>>nums[i];
    }
    stack<pair<int,int>> st;
    for(int i=0; i< m; i++)
    {
        int a, b; cin>>a>>b;
        b--;
        while(!st.empty() && st.top().second<=b)
        {
            st.pop();
        }
        st.push({a,b});
    }
    vector<pair<int,int>> q;
    while(!st.empty())
    {
        q.push_back(st.top());
        st.pop();
    }
    if(q.size()==0)
    {
        for(int i=0; i< n; i++)
        {
            cout<<nums[i]<<' ';
        }
        cout<<el;
        return;
    }
    vector<int> clone;

    int idx=(int)q.size()-1;
    for(int i=0; i<=q[idx].second; i++)
    {
        clone.push_back(nums[i]);
    }
    sort(clone.begin(),clone.end());
    vector<int> ans=nums;
    int l=0,r=clone.size()-1;
    int p;
    for(int i=q[(int)q.size()-1].second; i>=0; i--)
    {
        if(idx>=0 && q[idx].second==i)
        {
            p=q[idx].first;
            idx--;
        }
        if(p==1)
        {
            ans[i]=clone[r];
            r--;
        }
        else
        {
            ans[i]=clone[l];
            l++;
        }
    }
    for(int i=0; i< ans.size(); i++)
    {
        cout<<ans[i]<<' ';
    }
    cout<<el;

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









