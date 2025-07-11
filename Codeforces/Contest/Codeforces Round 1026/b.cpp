
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        string s;cin>>s;
        bool canchange=false;
        stack<char> st;
        for(int i=1; i<s.size()-1; i++)
        {
            if(!st.empty() && s[i]==')' && st.top()=='(')
            {
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        if(st.empty()) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
//        if(canchange) cout<<"YES"<<endl;
//        else cout<<"NO"<<endl;
    }
}
