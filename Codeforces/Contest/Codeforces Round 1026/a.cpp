
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {


        int n ;cin>>n;

        vector<int> dp;
        for(int i=0;  i< n; i++)
        {
            int x; cin>>x;dp.push_back(x);
        }
        sort(dp.begin(),dp.end());
        //cc;
        int l=0;
        int r=n-1;
//        cout<<"dp: ";
//        for(int i=0; i< dp.size(); i++)
//        {
//            cout<<dp[i]<<" ";
//        }
//        cout<<endl;
        //c & c
        while(l<n && dp[l]%2!=0)
        {
            l++;
        }
        while(r>=0 && dp[r]%2!=0)
        {
            r--;
        }
        //l l
        int c1=0,c2=n-1;
        while(c1<n && dp[c1]%2!=1)
        {
            c1++;
        }
         while(c1>=0 && dp[c2]%2!=1)
        {
            c2--;
        }
        //cout<<l<<" "<<r<<" "<<c1<<" "<<c2<<endl;
        cout<< min(n-1,min(l-0+n-1-r,c1-0+n-1-c2))<<endl;
    }
}
