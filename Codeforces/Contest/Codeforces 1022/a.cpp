#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int sum=0;
        int x=n;
        for(int i=1; i<= n; i++)
        {
            sum+=abs(x-i);
            x--;
        }
        cout<<sum/2+1<<endl;
    }
}
