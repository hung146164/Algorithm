#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n;
    vector<pair<int,int>> nums(n);
    for(int i=0; i< n; i++)
    {
        cin>>nums[i].first>>nums[i].second;
    }
    int ans=0;
    for(int i=0; i< n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            for(int k=j+1; k< n; k++)
            {
                int a=nums[i].first,b=nums[i].second;
                int a1=nums[j].first,b1=nums[j].second;
                int a2=nums[k].first,b2=nums[k].second;
                float dx=sqrt((a1-a)*(a1-a) + (b-b1)*(b-b1));
                float dy=sqrt((a2-a)*(a2-a) + (b-b2)*(b-b2));
                float dz=sqrt((a2-a1)*(a2-a1) + (b2-b1)*(b2-b1));
               // cout<<dx<<' '<<dy<<' '<<dz<<'\n';

                if( (dx+dy)==dz || (dy+dz)==dx || (dx+dz==dy)) continue;
                ans++;

            }
        }
    }
    cout<<ans<<'\n';
}

