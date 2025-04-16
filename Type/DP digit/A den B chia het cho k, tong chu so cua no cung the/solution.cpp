#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int inf=1e4;

int dp[10][90][2];
const int mod =1e9+7;
ll sol(string s,int curr, bool ti,int sum, int& k,int ht)
{
    ll ans=0;

    if(curr==s.size())
    {
        return sum%k==0 && ht%k==0;
    }
    if(dp[curr][sum][ti]!=-1) return dp[curr][sum][ti];
    if(ti)
    {
        int to = s[curr]-'0';
        for(int i=0; i<=to ;i++)
        {
            ans+=sol(s,curr+1,i==to,sum+i,k,ht*10+i);
        }
    }
    else{
        for(int i=0; i<10; i++)
        {
            ans+=sol(s,curr+1,false,sum+i,k,ht*10+i);
        }
    }
    dp[curr][sum][ti]=ans;
    return ans;
}
int main(void)
{
    memset(dp,-1,sizeof(dp));
    int a,b,k;cin>>a>>b>>k;
    string hi=to_string(b);
    string lo=to_string(a-1);
    cout<< sol(hi,0,true,0,k,0)-sol(lo,0,true,0,k,0)<<endl;
}
