#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fibo[92];
void process()
{
    fibo[0]=1;
    fibo[1]=2;
    for(int i=2; i<92;i++)
    {
        fibo[i]=fibo[i-2]+fibo[i-1];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=1; i<20 ;i++)
    {
       ll n=i;
        process();
        ll ans;
        while(n)
        {
            auto it=prev(upper_bound(fibo,fibo+92,n));
            n-=*it;
            ans=*it;
        }
        cout<<ans<<'\n';
    }

}


