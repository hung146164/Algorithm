#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define en '\n';

const int mod=1e9+7;
const int N=1e5+1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int t; cin>>t;
    while(t--)
    {
        int n,a,b; cin>>n>>a>>b;
        vector<int> nums;
        for(int i=0; i<n; i++)
        {
            int x; cin>>x;
            nums.push_back(x);
        }
        int first=nums[0];
        auto it=upper_bound(nums.begin(), nums.end(), first+a);
        if(it==nums.end())
        {
            cout<<"YES"<<en;
            continue;
        }
        auto it2=upper_bound(nums.begin(), nums.end(),*it+b);

        auto it3=upper_bound(nums.begin(), nums.end(), first+b);
        if(it3==nums.end())
        {
            cout<<"YES"<<en;
            continue;
        }
        auto it4=upper_bound(nums.begin(), nums.end(),*it3+a);

        if(it2==nums.end() || it4 ==nums.end()) cout<<"YES"<<'\n';
        else cout<<"NO"<<en;

    }
}
