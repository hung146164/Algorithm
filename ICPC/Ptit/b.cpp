#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin>>n;

    vector<int> nums;
    for(int i=0; i< n; i++)
    {
        int x; cin>>x;
        nums.push_back(x);
    }
    vector<int> chan,le;
    for(int i=0; i< nums.size(); i++)
    {
        if(i%2==0) chan.push_back(nums[i]);
        else le.push_back(nums[i]);
    }
    if(n%2==0)
    {
        for(int i=le.size()-1; i>=0; i--)
        {
            cout<<le[i]<<' ';
        }
        for(int i=0; i<chan.size(); i++)
        {
            cout<<chan[i]<<' ';
        }
    }
    else{
        for(int i=chan.size()-1; i>=0; i--)
        {
            cout<<chan[i]<<' ';
        }
        for(int i=0; i<le.size(); i++)
        {
            cout<<le[i]<<' ';
        }
    }
}
