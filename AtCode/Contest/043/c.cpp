#include<bits/stdc++.h>
#define ll long long
#define en "\n"
#define inf 1e18
//cout << setprecision(7) << fixed
#define MOD 1000000007
using namespace std;
#define BIT(x, i) (((i) >> (x))&1)
#define find(s,a) s.find(a)!=s.end()
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n;
    vector<int> nums;
    for(int i=0; i< n; i++)
    {
        int x; cin>>x;
        nums.push_back(x);
    }
    ll ans=INT_MAX;

    for(int can=-100; can<=100; can++)
    {
        ll val=0;
        for(int i=0; i< nums.size(); i++)
        {
            val=val+(nums[i]-can)*(nums[i]-can);
        }
        ans=min(ans,val);
    }
    cout<<ans<<en;
}

