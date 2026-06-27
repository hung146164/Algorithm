#include<bits/stdc++.h>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(nullptr);

    int n,t; cin>>n>>t;
    vector<pair<int,int>> nums,nuu;
    for(int i=0; i< n; i++)
    {
        int x; cin>>x;
        nums.push_back({x,i});
        nuu.push_back({i,x});
    }
    sort(nums.begin(),nums.end());
    int ans=1;
    for(int i=1; i< nums.size(); i++)
    {
        if(nums[i].second<nums[i-1].second) ans++;
    }
    while(t--)
    {
        int o,p; cin>>o>>p;
        o--;p--;
        int a=nuu[o].second;
        int b=nuu[p].second;
        swap(nuu[o],nuu[p]);
        a--;b--;
        if(a>b) swap(a,b);
        if(a>0 && nums[a].second < nums[a-1].second) ans--;
        if(a<n-1 && nums[a].second>nums[a+1].second) ans--;
        //cout<<"x "<<ans<<'\n';
        if(b>0 && nums[b].second < nums[b-1].second && a!=b-1) ans--;
        if(b<n-1 && nums[b].second>nums[b+1].second) ans--;
        swap(nums[a].second,nums[b].second);

        if(a>0 && nums[a].second < nums[a-1].second) ans++;
        if(a<n-1 && nums[a].second>nums[a+1].second) ans++;

        if(b>0 && nums[b].second < nums[b-1].second && a!=b-1) ans++;
        if(b<n-1 && nums[b].second>nums[b+1].second) ans++;
        cout<<ans<<'\n';
//        for(int i=0; i< nums.size(); i++)
//        {
//            cout<<nums[i].first<<' '<<nums[i].second<<'\n';
//        }
    }
}
