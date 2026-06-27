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
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int u=0,y=0;
        bool have=false;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='U') u++;
            else y++;
            if(i-3>=0)
            {
                if(s[i-3]=='U') u--;
                else y--;
            }
            if(u==2 && y==1)
            {
                have=true;
               cout<<"YES\n";
                cout<<i-1<<' '<<i+1<<'\n';
                break;
            }
            if(u==1&&y==2)
            {
                have=true;
                cout<<"YES\n";
                cout<<i-1<<' '<<i+1<<'\n';
                break;
            }
        }
        if(!have) cout<<"NO\n";
    }


}


