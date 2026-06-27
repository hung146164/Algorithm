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

    int t; cin>>t;
    while(t--)
    {
        int n,k; cin>>n>>k;
        vector<int> nums;
        for(int i=0; i< n; i++)
        {
            int x; cin>>x;
            nums.push_back(x);
        }
        sort(nums.begin(),nums.end());
        bool checkfirst=true;
        for(int i=0; i< nums.size(); i++)
        {
            if(nums[i]>k)
            {
                checkfirst=false;
                break;
            }
        }
        if(nums[0]+nums[1]<=k || checkfirst) cout<<"YES"<<'\n';
        else cout<<"NO\n";
    }

}


