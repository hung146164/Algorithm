#include<bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<int,int> dp;
    int n ; cin>> n;

    for(int i=0; i< n ; i++)
    {
        int x; cin>>x;
        dp[x]++;
    }
    cout<<dp.size()<<endl;
}
