#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> nums;
        for(int i=0; i< n; i++)
        {
            int x; cin>>x;
            nums.push_back(x);
        }
        sort(nums.begin(),nums.end(),greater<int>());
        ll ans=0;
        for(int i=0; i<nums.size(); i+=2)
        {
            ans+=nums[i];
        }
        cout<<ans<<'\n';
    }
}
