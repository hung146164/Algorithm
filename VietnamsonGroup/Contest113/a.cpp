#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+5;
const int mod=1e9+7;

unordered_map<string,int> dp;

int sol(string& s, int pre,int curr)
{
    if(curr==s.size())
    {
        return dp.size();
    }
    string val=s.substr(pre,curr-pre+1);
    int ans=0;
    if(dp.find(val)==dp.end())
    {
        dp[val]=1;
        ans=max(ans,sol(s,curr+1,curr+1));
        dp.erase(val);
    }
    ans=max(ans,sol(s,pre,curr+1));
    return ans;
}
void solve()
{
    string s; cin>>s;
    cout<< sol(s,0,0)<<'\n';
}

signed main()
{
    solve();
}








