#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

typedef long long ll;
int pow(int a,int b)
{
    int ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=1LL*ans*a%mod;
        }
        a=1LL*a*a %mod;
        b/=2;
    }
    return ans;
}
int main()
{
    int a, N; cin>>a>>N;
    cout<<pow(a,N)<<'\n';
}
