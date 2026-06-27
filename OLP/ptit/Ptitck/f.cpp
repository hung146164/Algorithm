#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int can[3]{3,5,7};
int dp[10][2][2][2][2];
int sol(string& s,int curr=0,bool first=true,bool co3=false, bool co5=false,bool co7=false)
{
    if(s.size()==curr)
    {
        if(co3 && co5 && co7) return 1;
        return 0;
    }
    if(dp[curr][first][co3][co5][co7]!=-1) return dp[curr][first][co3][co5][co7];
    int ans=0;
    if(!co3 && !co5 && !co7) ans+=sol(s,curr+1,false,co3,co5,co7);
    if(first)
    {
        for(int i=0; i<3; i++)
        {
            if(can[i]==s[curr]-'0')
            {
               ans+=sol(s,curr+1,true,(can[i]==3) | co3, (can[i]==5) | co5,(can[i]==7) | co7);
            }
            else if(can[i]<s[curr]-'0')
            {
                ans+=sol(s,curr+1,false,can[i]==3 | co3, can[i]==5 | co5,can[i]==7 | co7);
            }
        }
    }
    else{
        for(int i=0; i<3; i++)
        {
            ans+=sol(s,curr+1,false,can[i]==3 | co3, can[i]==5 | co5,can[i]==7 | co7);
        }
    }
    return dp[curr][first][co3][co5][co7]=ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n;
    memset(dp,-1,sizeof(dp));
    string s=to_string(n);
    cout<<sol(s)<<'\n';
}


