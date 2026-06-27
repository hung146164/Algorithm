#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int nums[N];
int x[]{500,100,50,10,5,1};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int need=1000-n;
        int cnt=0;
        for(int i=0;i<6;i++)
        {
            if(need>=x[i])
            {
                cnt+=need/x[i];
                need%=x[i];
            }
        }
        cout<<cnt<<'\n';
    }

}
