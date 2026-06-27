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

    int n,m;
    cin>>n>>m;
    vector<int> buoc(n),dp(n);
    vector<int> nums;
    for(int i=0; i< n; i++)
    {
        int x;
        cin>>x;
        nums.push_back(x);
    }
    int ans=0;
    for(int i=0; i<n-1; i++)
    {
        buoc[i+1]=(nums[i+1]-nums[i]+m )%m;
        ans+=buoc[i+1];
    }

    vector<int> save(m);

    for(int i=0; i< n-1; i++)
    {
        if(nums[i]==nums[i+1] || ( (nums[i]+1) %m) == nums[i+1]) continue;
        int l,r;
        if(nums[i]<nums[i+1])
        {
            l=min(nums[i]+2,nums[i+1]);
            r=nums[i+1];
        }
        else
        {
            if( (nums[i]+1 )%m == nums[i+1])
            l=(nums[i]+2)%m;
            r=nums[i+1];
        }
        while(l!=r)
        {
            save[l]+=buoc[i]-((r-l+m)%m+1);
            l=(l+1)%m;
        }
    }
    int maxsave=0;
    for(int i=0; i< save.size(); i++)
    {
        maxsave=max(save[i],maxsave);
    }

    cout<<ans-maxsave-2<<'\n';


}


