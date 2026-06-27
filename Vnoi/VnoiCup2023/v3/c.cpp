#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define en '\n';

const ll mod=1e9+7;
const ll N=1e5+1;
int ans[N];
int sol(vector<int>& nums ,int curr=0,int thattrai=0)
{
    if(nums[curr]==1 && doitrai>=sol(nums,curr+1,thattrai+1))
    {
        ans[curr]=1;
    }
    else ans[curr]=0;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll t; cin>>t;
    while(t--)
    {
        int n; cin>> n;
        vector<int> nums;
        for(int i=0; i< n; i++)
        {
            int x; cin>>x;
            nums.push_back(x);
        }
        cout<<sol(nums);
    }
}
