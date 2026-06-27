#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int sol(int a, int b)
{
    if(b>a) return 2;
    if(a<=2) return -1;
    if(b==a-1) return -1;
    if(b==1) return -1;
    if(b==a) return -1;
    return 3;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--)
    {
        int a, b; cin>>a>>b;
        cout<<sol(a,b)<<'\n';
    }
    ;
}

