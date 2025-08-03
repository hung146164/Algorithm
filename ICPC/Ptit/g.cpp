#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sol(int n)
{
    if(n==0) return 2;
    if(n==1) return 1;
    ll a=2,b=1;
    for(int i=2; i<=n; i++)
    {
        ll temp=a+b;
        a=b;
        b=temp;
    }
    return b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin>>n;
    cout<<sol(n)<<'\n';
}

