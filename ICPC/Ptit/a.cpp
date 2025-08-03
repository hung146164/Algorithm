#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin>>n;

    vector<int> nums;
    int sum=0;
    for(int i=0; i< n; i++)
    {
        int x; cin>>x;
        nums.push_back(x);
        sum+=x;
    }

    sort(nums.begin(),nums.end());
    int maxx=nums[nums.size()-1];

    if(n<3 || sum-maxx<=maxx)
    {
        cout<<"No"<<'\n';
    }
    else cout<<"Yes"<<'\n';
}
