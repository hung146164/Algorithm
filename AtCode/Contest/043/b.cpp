#include<bits/stdc++.h>
#define ll long long
#define en "\n"
#define inf 1e18
//cout << setprecision(7) << fixed
#define MOD 1000000007
using namespace std;
#define BIT(x, i) (((i) >> (x))&1)
#define find(s,a) s.find(a)!=s.end()
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;cin>>s;
    stack<char> st;
    for(int i=0; i< s.size(); i++)
    {
        if(s[i]=='B')
        {
            if(!st.empty()) st.pop();
        }
        else st.push(s[i]);
    }
    string ans;
    while(!st.empty())
    {
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<en;
}

