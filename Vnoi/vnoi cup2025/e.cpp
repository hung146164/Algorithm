#include<bits/stdc++.h>
using namespace std;
int fact[1025];
const int mod=998244353;

typedef long long ll;
ll mu(ll a, ll b) {
    ll result = 1;
    while (b > 0) {
        if (b % 2 == 1) result = (result* a)%mod;
        a =(a* a)%mod;
        b /= 2;
    }
    return result;
}
ll revemodulo(ll val,int m)
{
    return mu(val,m-2)%mod;
}
typedef long long ll;

ll tohop(int n,int k)
{
    return 1LL*fact[n]*revemodulo(1LL*fact[n-k]*fact[k],mod)%mod;
}
void process()
{
    fact[0]=1;
    for(int i=1;i<1025; i++)
    {
        fact[i]=(1LL*fact[i-1]*i)%mod;
    }
}
int main()
{
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    process();
    int t; cin>>t;
    while(t--)
    {
        int n,k; cin>>n>>k;
    int b=0, a=0;
    for(int i=0; i< n ;i++)
    {
        int x; cin>>x;
        if(x==0) b++;
        else a++;
    }
    ll cc=(1LL*fact[a]*fact[b])%mod;
    ll sum=0;
    for(int i=0; i<a; i++)
    {
        sum=(sum+cc*(a-i)*tohop(b+i-1,i))%mod;
    }
    cout<<sum<<'\n';
    }

}
