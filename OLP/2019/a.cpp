#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=1e5+1;

ll maxll(ll a,ll b)
{
    if(a>b) return a;
    return b;
}
ll minll(ll a,ll b)
{
    if(a>b) return b;
    return a;
}
ll gdc(ll a, ll b)
{
    if(b==0) return a;
    return gdc(b,a%b);
}

namespace sub1
{
    bool CheckSub1()
    {
        return true;
    }
    void sol()
    {

    }
}
namespace sub2
{
    bool CheckSub2()
    {
        return true;
    }
    void sol()
    {

    }
}
namespace sub3
{
    bool CheckSub3()
    {
        return true;
    }
    void sol()
    {

    }
}
unordered_map<char,int> hextoten;
unordered_map<int,char> tentohex;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin>>s;
    string t; cin>>t;

    for(int i=0; i< s.size(); i++)
    {
        s[i]=uppercase(s[i]);
    }
    for(int i=0; i <t.size(); i++)
    {
        t[i]=uppercase(t[i]);
    }
    for(int i=0;i<10; i++)
    {
        hextoten[i+'0']=i;
        tentohex[i]=i+'0';
    }
    hextoten['A']=10;
    hextoten['B']=11;
    hextoten['C']=12;
    hextoten['D']=13;
    hextoten['E']=14;
    hextoten['F']=15;

    tentohex[10]='A';
    tentohex[11]='B';
    tentohex[12]='C';
    tentohex[13]='D';
    tentohex[14]='E';
    tentohex[15]='F';
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
    ll ans=0;
    for(int i=0; i< s.size(); i++)
    {
        //ans=(ans+hextoten[s[i]]*pow16[i]%15)%15;
    }

}

