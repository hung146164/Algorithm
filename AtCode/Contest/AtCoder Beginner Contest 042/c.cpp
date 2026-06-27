#include<bits/stdc++.h>
#define ll long long
#define en "\n"
#define inf 1e18
//cout << setprecision(7) << fixed
#define MOD 1000000007
using namespace std;
#define BIT(x, i) (((i) >> (x))&1)
#define find(s,a) s.find(a)!=s.end()
bool iscontainfull(int curr,vector<int>& can)
{
    while(curr)
    {
        for(int i=0; i< can.size(); i++)
        {
            if( (curr%10) == can[i]) return false;
        }
        curr/=10;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; cin>>n>>m;
    vector<bool> hate(10);
    for(int i=0; i< m; i++)
    {
        int x; cin>>x;
        hate[x]=true;
    }
    vector<int> can;
    vector<int> nocan;
    for(int i=0; i< 10; i++)
    {
        if(!hate[i])
        {
            can.push_back(i);
        }
        else nocan.push_back(i);
    }
    sort(can.begin(),can.end());
    int curr=0;
    if(can[0]==0)
    {
        curr*=10;
        curr+=can[1];
    }
    while(curr<n)
    {
        curr*=10;
        curr+=can[0];
    }
    int ans=n;
    for(int i=n;i<=curr; i++)
    {
        if(iscontainfull(i,nocan))
        {
            ans=i;
            break;
        }
    }
    cout<<ans<<en;
}

