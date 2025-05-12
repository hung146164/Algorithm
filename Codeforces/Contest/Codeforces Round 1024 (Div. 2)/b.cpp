
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vector<int> dp;
        for(int i=0; i< n; i++)
        {
            int x; cin>>x;
            dp.push_back(x);
        }
        int val=abs(dp[0]);
        int co=0;
        int me=n/2;
        for(int i=1; i< dp.size(); i++)
        {
            if(val>abs(dp[i])) co++;
        }
        int mi=min(co,n-co);
        int ma=max(co,n-co);
        if(me<=ma && me>=mi) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
}
