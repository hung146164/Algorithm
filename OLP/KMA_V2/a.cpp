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

    int n,d; cin>>n>>d;
    vector<int> nums;
    for(int i=0;i<n; i++)
    {
        int x; cin>>x;
        nums.push_back(x);
    }
    sort(nums.begin(),nums.end());
    int l=0,r=nums.size()-1;
    int ans=0;
    while(l<=r)
    {
        ans++;
        int val=0;
        while(r>=l && val+nums[r]<=d)
        {
            val+=nums[r];
            r--;
        }
        while(l<=r && val+nums[l]<=d)
        {
            l++;
            val+=nums[l];
        }
    }
    cout<<ans<<'\n';
}

