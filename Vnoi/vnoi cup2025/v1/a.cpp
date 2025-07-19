#include<bits/stdc++.h>
using namespace std;
pair<int,int> sol(string s)
{
    if(s.size()<3) return {-1,-1};
    int u=0,y=0;
    for(int i=0;i<s.size(); i++)
    {
        if(s[i]=='I') y++;
        else u++;

        if(i-3>=0)
        {
            if(s[i-3]=='I') y--;
            else u--;
        }
        if(u>0 && y>0)
        {
            if(u>=2*y || y>=2*u)
            {
                return {i-2,i};
            }
        }
    }
    return {-1,-1};
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--)
    {
        string s;cin>>s;
        pair<int,int> ans=sol(s);

        if(ans.first==-1 && ans.second==-1)
        {
            cout<<"NO"<<'\n';
        }
        else{
            cout<<"YES"<<' ';
            cout<<ans.first+1<<' '<<ans.second+1<<'\n';

        }
    }

}
