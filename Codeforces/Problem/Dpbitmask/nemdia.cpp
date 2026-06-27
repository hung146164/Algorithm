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
struct bo
{
    public:
    int h,can,sk;
    bo(int _h,int _can,int _sk)
    {
        this.h=_h;
        this.can=_can;
        this.sk=_sk;
    }

};
pair<bool,int> sol(int curr,vector<bo>& bos,int mask=0)
{
    int n=bos.size();
    int currcan=0;
    for(int i=0; i< n; i++)
    {
        if(mask>>i &1) currcan+=bos[i].can;
    }

    for(int i=0; i< n; i++)
    {
        if((mask>>i)&1 || bos[i].sk<currcan) continue;

        sol(i,bos,mask|(1<<i));
    }

}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,Hvalid; cin>>n>>Hvalid;
    vector<bo> bos
    for(int i=0; i<n;i++)
    {
        int a,b,c; cin>>a>>b>>c;
        bos.push_back(bo(a,b,c));
    }
    cout<<sol(-1,g,h)<<'\n';

}

