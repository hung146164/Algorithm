#include<bits/stdc++.h>
#define ll long long
#define en "\n"
#define inf 1e18
//cout << setprecision(7) << fixed
#define MOD 1000000007
using namespace std;
#define BIT(x, i) (((i) >> (x))&1)
#define find(s,a) s.find(a)!=s.end()

ll epath(ll a, ll b,ll c, ll d)
{
    return (a-b)*(a-b) + (c-d)*(c-d);
}
bool cmp(pair<ll,ll>& a, pair<ll, ll >& b)
{
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin>>n;
    vector<pair<ll,ll>> nums;
    for(ll i=0; i< n; i++)
    {
        ll a, b; cin>>a>>b;
        nums.push_back({a,b});
    }

    map<ll,vector<ll>> dp;
    for(ll i=0; i< nums.size(); i++)
    {
        dp[nums[i].first].push_back(nums[i].second);
    }
    vector<vector<ll>> duongtheox;
    unordered_map<ll,ll> postorank,ranktopos;
    ll cnt=0;
    for(pair<ll,vector<ll>> curr : dp)
    {
        duongtheox.push_back(curr.second);
        postorank[curr.first]=cnt;
        ranktopos[cnt]=curr.first;
        cnt++;
    }
    vector<ll> ans(5,INT_MAX);
    for(ll i=0; i< duongtheox.size(); i++)
    {
        for(ll j=0; j< duongtheox[i].size(); j++)
        {
            if(j>0)
            {
                ll len=epath(ranktopos[i],duongtheox[i][j],ranktopos[i],duongtheox[i][j-1]);
                if(len<ans[0])
                {
                    ans[0]=len;
                }
            }
            if(i>0)
            {
                auto it= duongtheox[i-1].upper_bound(duongtheox[i-1].begin(),duongtheox[i-1].end(),duongtheox[i][j]);
                ll len=INT_MAX;
                if(it!=duongtheox[i-1].end()) len=min(len,epath(ranktopos[i],duongtheox[i][j],ranktopos[i-1],*it));

                if(it!=duongtheox.begin()) len=min(len,epath(ranktopos[i],duongtheox[i][j],ranktopos[i-1],*prev(it)));
                if(len<ans[0])
                {
                    ans[0]=len;
                }
            }
        }
    }
    cout<<ans[0]<<'\n';
}

