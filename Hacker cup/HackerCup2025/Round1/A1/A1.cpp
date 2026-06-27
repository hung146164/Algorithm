#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=1e5+1;


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("snake_scales_chapter_1_input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t; cin>>t;
    for(int k=1;k<=t; k++)
    {
        int n; cin>>n;
        vector<int> nums;
        for(int i=0; i< n; i++)
        {
            int x; cin>>x;
            nums.push_back(x);
        }
        int ans=0;
        for(int i=1; i< nums.size(); i++)
        {
            ans=max(ans,abs(nums[i]-nums[i-1]));
        }
        cout<<"Case #"<<k<<": "<<ans<<'\n';
    }
}


