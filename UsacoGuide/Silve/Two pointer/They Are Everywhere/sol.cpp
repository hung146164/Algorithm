#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin>>n;
    string s;cin>>s;
    int dif=0;
    unordered_map<char,int> dp;
    for(int i=0; i< s.size(); i++)
    {
        dp[s[i]]++;
    }
    dif=dp.size();
    unordered_map<char,int> m;
    int ans=n;
    for(int l=0,r=0; r<n ;r++)
    {
        m[s[r]]++;

        while(m.size()==dif)
        {
            ans=min(ans,r-l+1);
            m[s[l]]--;

            if(m[s[l]]==0) m.erase(s[l]);
            l++;

        }
    }
    cout<<ans<<endl;
}
