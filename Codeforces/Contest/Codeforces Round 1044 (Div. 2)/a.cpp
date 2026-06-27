#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
bool sol(vector<int>& nums)
{
    int n=nums.size();
    for(int i=0; i< n; i++)
    {
        for(int j=i+1; j< n; j++)
        {
            if((nums[i]==nums[j]) ) return true;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vector<int> nums;
        for(int i=0; i<n; i++)
        {
            int x; cin>>x;
            nums.push_back(x);
        }
        cout<<(sol(nums)?"YES":"NO")<<'\n';
    }
}

