#include<bits/stdc++.h>
#define ll long long
#define en "\n"
#define inf 1e18
//cout << setprecision(7) << fixed
#define MOD 1000000007
using namespace std;
#define BIT(x, i) (((i) >> (x))&1)
#define find(s,a) s.find(a)!=s.end()
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c; cin>>a>>b>>c;
    int f=0,s=0;
    if(a==5) f++;
    if(b==5) f++;
    if(c==5) f++;
    if(a==7) s++;
    if(b==7) s++;
    if(c==7) s++;
    cout<<(f==2 && s==1?"YES":"NO")<<en;
}
