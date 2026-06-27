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

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> nums;
    for(int i=0; i< n; i ++)
    {
        int x;
        cin>>x;
        nums.push_back(x);
    }
    int ans=0;
    for(int i=0; i< n; i++)
    {
        unordered_map<int,int> d;
        for(int j=i; j< n; j++)
        {
            d[nums[j]]++;
            vector<bool>check(10000);
            for(auto l:d)
            {
                check[l.second]=true;
            }
            bool ok=true;
            for(int l=1; l<=k; l++)
            {
                if(!check[l])
                {
                    ok=false;
                    break;
                }
            }
            if(ok) ans++;
        }


    }
    cout<<ans<<'\n';
}


