#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q; cin>>n>>q;
    vector<int> nums(n);
    for(int i=0; i< n;i ++)
    {
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end());
    while(q--)
    {
        ll x, cay; cin>>x>>cay;
        ll l=0, r=1e15;
        ll ans=1e15;
        while(l<=r)
        {
            ll m=l+(r-l)/2;
            auto it1=lower_bound(nums.begin(), nums.end(),x-m);

            auto it2=upper_bound(nums.begin(), nums.end(),x+m);
            //if(m==3) cout<<it1-nums.begin()<<" "<<it2-nums.begin()<<endl;
            ll socay=it2-nums.begin()-(it1-nums.begin());
            if(socay>=cay)
            {
                ans=min(ans,m);
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        cout<<ans<<'\n';
    }
}
