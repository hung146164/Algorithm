#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int t;cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vector<int> dp;
         int index=0;
        int maxx=0;
        for(int i=0; i< n; i++)
        {
            int x; cin>>x;
            dp.push_back(x);
            if(maxx<x)
            {
                maxx=x;
                index=i;
            }
        }

        sort(dp.begin(),dp.end());
        bool checkequal=true;
        for(int i=1; i<dp.size(); i++)
        {
            if(dp[i]!=dp[i-1])
            {
                checkequal=false;
                break;
            }
        }
        if(!checkequal)
        {
            cout<<"Yes"<<endl;
            for(int i=0; i< n; i++)
        {
            if(index==i) cout<<1<<" ";
            else cout<<2<<" ";
        }
        cout<<endl;
        }
        else cout<<"No"<<endl;


    }
}

