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

    int n,k; cin>>n>>k;
    vector<int> nguoi;
    for(int i=0; i< n; i++)
    {
        int x; cin>>x;
        nguoi.push_back(x);
    }
    vector<pair<int,int>> dp(1<<n,{mod,mod});
    dp[0]={0,0};
    for(int state=1; state<(1<<n);state++)
    {
        pair<int,int> candidate=dp[state];
        for(int i=0; i< n; i++)
        {
            if( (state>>i) & 1)
            {

                pair<int,int> toiuutruoc= dp[state^(1<<i)];
                //cout<<"hh "<<toiuutruoc.first<<' '<<toiuutruoc.second<<'\n';
                int sothang=toiuutruoc.first;
                int sodu=toiuutruoc.second;

                if(sodu<nguoi[i])
                {
                    int newthang=sothang+1;
                    int newdu=k-nguoi[i];
                    if(candidate.first>newthang)
                    {
                        candidate={newthang,newdu};
                    }
                    else if(candidate.first==newthang && candidate.second< newdu)
                    {
                        candidate={newthang,newdu};
                    }
                }
                else{
                    int newthang=sothang;
                    int newdu=sodu-nguoi[i];
                    if(candidate.first>newthang)
                    {
                        candidate={newthang,newdu};
                    }
                    else if(candidate.first==newthang && candidate.second< newdu)
                    {
                        candidate={newthang,newdu};
                    }
                }
            }
        }
        //cout<<candidate.first<<' '<<candidate.second<<'\n';
        dp[state]=candidate;
    }
//    for(int i=0; i<(1<<n);i++)
//    {
//        cout<<dp[i].first<<' '<<dp[i].second<<'\n';
//    }
    cout<<dp[(1<<n)-1].first<<'\n';
}

