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
    int n; cin>>n;
    vector<int> nums(n);

    for(int i=0; i< n; i++)
    {
        cin>>nums[i];
    }
    int ans=0;
    for(int i=0;i < n ;i++)
    {
        if( ((n-1)&i) ==i) ans^=nums[i];
    }
    cout<<ans<<'\n';
}


