#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> mnt;
const int INF=1e5;
bool nt[INF];
int dp[20][2][20*9];
int sol(string s,int sum, bool rb,int curr)
{
    if(curr==s.size())
    {
        return  (mnt.find(sum)!=mnt.end());
    }
    if(dp[curr][rb][sum]!=-1) return dp[curr][rb][sum];
    int ans=0;
    if(rb)
    {
        int to=s[curr]-'0';
        for(int i=0; i<=to; i++)
        {
            ans+=sol(s,sum+i,(i==to?true:false),curr+1);
        }
    }
    else
    {
        for(int i=0; i<10; i++)
        {
            ans+=sol(s,sum+i,false,curr+1);
        }
    }
    dp[curr][rb][sum]=ans;
    return ans;
}
void sang(int n)
{
    memset(nt,true,sizeof(nt));
    for(int i=2; i<=n; i++)
    {
        if(nt[i])
        {
            mnt[i]++;
            for(int j=i*i;j<=n; j+=i)
            {
                nt[j]=false;
            }
        }
    }
}
int main(void)
{

    int l, r; cin>> l>>r;
    string lo=to_string(l-1);
    string hi=to_string(r);
    sang(hi.size()*9);
    memset(dp,-1,sizeof(dp));
    int ans1=sol(hi,0,true,0);
    memset(dp,-1,sizeof(dp));
    int ans2=sol(lo,0,true,0);
    cout<<ans1-ans2<<endl;
}
