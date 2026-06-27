#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void sub2()
{
    string s;cin>>s;
    vector<ll> prefix(s.size()+1);
    vector<ll> even(s.size()+1);
    for(ll i=0; i< s.size(); i++)
    {
        prefix[i+1]=prefix[i];
        even[i+1]=even[i];
        if((s[i]-'0')%2==0)
        {
            prefix[i+1]+=i+1;
            even[i+1]++;
        }
    }
    ll q;cin>>q;
    while(q--)
    {
        ll a, b; cin>>a>>b;
        cout<<prefix[b]-prefix[a-1]-(even[b]-even[a-1])*(a-1)<<'\n';
    }
}
ll sol(string s, ll a, ll b, ll p)
{
    a--;
    b--;
    ll ans=0;
    for(int i=a; i<=b; i++)
    {
        int val=0;
        for(int j=0; j<= b-i; j++)
        {
            val*=10;
            val+=s[i+j]-'0';
            val%=p;
            if(val==0) ans++;
        }
    }
    return ans;
}
void sub1(ll&p)
{
    string s;cin>>s;
    ll q;cin>>q;
    while(q--)
    {
        ll a, b; cin>>a>>b;
        cout<<sol(s,a,b,p)<<'\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    ll p; cin>>p;
    if(p==2) sub2();
    else
    {
        sub1(p);
    }

}
