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
    int l=0;
    int r=n-1;
    int ans=n;
    while(l<=r)
    {
        int m=l+(r-l)/2;

        unordered_map<char,int> ma;
        bool check=false;
        for(int i=0; i< n ; i++)
        {
            ma[s[i]]++;
            if(i>=m)
            {
                ma[s[i-m]]--;
                if(ma[s[i-m]]==0)
                {
                    ma.erase(s[i-m]);
                }

            }
            if(ma.size()==dif)
            {
                check=true;
                break;
            }
        }

        if(check)
        {
           // cout<<m<<endl;
            //ans=min(ans,m);
            r=m-1;
        }
        else{
            l=m+1;
        }
    }
    cout<<l<<endl;
}
