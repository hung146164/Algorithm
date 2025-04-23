#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        string s;cin>>s;
        unordered_map<int,int> dp;
        vector<int> x;
        x.push_back(1);
        int curr=1;
        dp[1]=1;
        int minn=1;
        for(int i=0; i< s.size(); i++)
        {
            if(s[i]=='<')
            {
                while(dp[curr]==1)
                {
                    curr--;
                }
                x.push_back(curr);
                dp[curr]=1;
            }
            else{
               while(dp[curr]==1)
                {
                    curr++;
                }
                dp[curr]=1;
                x.push_back(curr);
            }
            minn=min(minn,curr);
        }
        if(minn!=1)
        {
            for(int i=0; i<x.size(); i++)
            {
                x[i]+=(1-minn);
            }
        }
        for(int i=0; i< x.size(); i++) cout<< x[i]<<" ";
        cout<<endl;

    }
    return 0;
}
