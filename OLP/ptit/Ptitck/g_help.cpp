#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void hoanvi(int n,int mask=0,int have=0,int clone=0)
{
    if(have==n) cout<<clone<<'\n';
    for(int i=1; i<=5; i++)
    {
        if( !(mask&(1<<i)))
        {
            mask^=(1<<i);
            clone*=10;
            clone+=i;
            hoanvi(n,mask,have+1,clone);
            clone/=10;
            mask^=(1<<i);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    hoanvi(5);
}


