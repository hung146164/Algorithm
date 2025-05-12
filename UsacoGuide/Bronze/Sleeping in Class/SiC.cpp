#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vector<int> dp;
        int MAX=0;
        int mi=INT_MAX;
        for(int i=0; i< n; i++)
        {
            int x; cin>>x;
            dp.push_back(x);
            MAX+=x;
            mi=min(x,mi);
        }
        int ans=INT_MAX;
        for (int i=1;i<=MAX; i++)
        {
            if(MAX%i!=0) continue;
            bool check=true;
            int sum=0;
            int tongmang=0;
            int c=0;
            for(int j=0; j< n;j ++)
            {
                sum+=dp[j];
                c++;
                if(sum>i)
                {
                    check=false;
                    break;
                }
                else if(sum==i)
                {
                    sum=0;
                    tongmang+=c-1;
                    c=0;
                }
            }
            if(sum!=0) check=false;
            //cout<<"i "<<i<<"tong mang: "<<tongmang<<" check"<<check<<endl;
            if(check)
            {
                ans=min(ans,tongmang);
            }
        }
        cout<<(ans==INT_MAX?0:ans)<<endl;
    }
}
