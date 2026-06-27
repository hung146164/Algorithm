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

    int x; cin>>x;
    int c=0;
    vector<int> h;
    for(int i=9;i>=0; i--)
    {
        if(x>>i &1)
        {
            c++;
            h.push_back(i);
        }
        cout<<(x>>i &1);
    }
    sort(h.begin(),h.end());
    cout<<' '<<c<<'\n';
    for(int i=0; i< h.size(); i++)
    {
        int v=h[i];
        cout<<(1<<v)<<' ';
        for(int j=9; j>=0; j--)
        {
            cout<<(j==v?1:0);
        }
        cout<<'\n';
    }
    int a,b; cin>>a>>b;
    cout<<(a^b)<<'\n';



}


