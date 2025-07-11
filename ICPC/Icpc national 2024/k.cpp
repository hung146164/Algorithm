#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool sol(int& n,int& a, int& b, int curr,int count,vector<ll>& prefix,string& s,vector<vector<vector<int>>>& dp)
{
   bool ans=false;

   if(curr==n) return true;
   int value=(s[curr]-'0'+count)%2;
   if(dp[curr][count][s[curr]-'0']!=-1) return dp[curr][count][s[curr]-'0'];
   count+=prefix[curr];
  // cout<<"curr: "<<curr<<" count "<<count<<" count+ s[curr] "<<s[curr]-'0'+count<<endl;
   if(value==1)
   {
       ans|=sol(n,a,b,curr+1,count,prefix,s,dp);
       for(int i=a; i<=b; i++)
       {
           if(curr+i<=n)
           {
               prefix[curr+i]--;
               for(int j=i+1; j<=b; j++)
               {
                   if(j+curr<=n)
                   {
                       prefix[j+curr]--;
                       ans|=sol(n,a,b,curr+1,count+2,prefix,s,dp);
                       prefix[j+curr]++;
                   }
               }
               prefix[curr+i]++;
           }
           else
           {
                break;
           }

       }
   }
   else
   {
       for(int i=a; i<=b; i++)
       {
           if(i+curr>n) break;
           prefix[i+curr]--;
           ans|=sol(n,a,b,curr+1,count+1,prefix,s,dp);
           prefix[i+curr]++;
       }
   }
   dp[curr][count][s[curr]-'0']=ans;
   return ans;
}
int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    {
        int n,a,b;
        cin>>n>>a>>b;
        string s;cin>>s;
        vector<ll> prefix(n+1);
        vector<vector<vector<int>>> dp(101,vector<vector<int>>(201,vector<int>(2,-1)));
        cout<<(sol(n,a,b,0,0,prefix,s,dp)==false?"NO":"YES")<<endl;

    }
}
