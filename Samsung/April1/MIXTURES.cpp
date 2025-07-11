#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    for(int i=1; i<= n; i++)
    {
        string s;cin>>s;
        int ans=0;
        for(int i=0; i< s.size(); i++)
        {
            ans+=s[i];
        }
        cout<<"Case "<<i<<": "<<(ans%3==0?"Yes":"No")<<'\n';
    }




}
