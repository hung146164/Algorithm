#include<bits/stdc++.h>
using namespace std;
int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--)
    {
        int n,x; cin>>n>>x;

        vector<int> dp;
        for(int i=0; i< n; i++)
        {
            int p;cin>>p;
            dp.push_back(p);
        }
        vector<int> clone=dp;
        for(int i=0; i< n; i++)
        {
            if(dp[i]==-1) dp[i]=x;
        }
        sort(dp.begin(),dp.end());
        if(dp[(dp.size()-1)/2]==x)
        {
            cout<<"YES"<<endl;
            for(int i=0; i<clone.size(); i++)
            {
                if(clone[i]==-1) cout<<x<<" ";
                else cout<<clone[i]<<" ";
            }
            cout<<endl;
        }
        else cout<<"NO"<<endl;

    }
}
