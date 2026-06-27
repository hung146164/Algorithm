#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define en '\n';

const ll mod=1e9+7;
const ll N=1e5+1;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n,k; cin>>n>>k;
    vector<int> nums;
    vector<int> prefix(1,0);
    vector<int> type;
    for(int i=0;i <n; i++)
    {
        int x; cin>>x;
        type.push_back(x);
    }
    for(int i=0; i< n; i++)
    {
        int x; cin>>x;

        nums.push_back(x);
        prefix.push_back(prefix[i]+nums[i]);
    }


    vector<int> ans;

}
