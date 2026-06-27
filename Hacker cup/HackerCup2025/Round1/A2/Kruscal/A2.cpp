#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 500000 + 5;
ll parent[N],len[N];
ll find(ll p)
{
    if(p==parent[p])
    {
        return p;
    }
    return parent[p]=find(parent[p]);
}
void join(ll u,ll v)
{
    ll pa=find(u);
    ll pb=find(v);
    if(pa==pb) return;
    if(len[pa]<len[pb]) swap(pa,pb);
    parent[pb]=pa;
    len[pa]+=len[pb];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("snake_scales_chapter_2_input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll t; cin>>t;

    for(ll k=1; k<=t; k++){
        ll n; cin>>n;
        vector<ll> nums;
        for(ll i=0; i<n; i++)
        {
            ll x; cin>>x;
            nums.push_back(x);
        }
        vector<vector<ll>> e;
        for(ll i=0; i<n; i++)
        {
            e.push_back({nums[i],0,i+1});
        }
        for(ll i=0; i< n-1; i++)
        {
            e.push_back({abs(nums[i+1]-nums[i]),i+1,i+2});
        }
        sort(e.begin(),e.end());
        for(ll i=0; i<=n; i++)
        {
            parent[i]=i;
            len[i]=1;
        }
        ll ans=0;
        for(ll i=0; i<e.size();i++)
        {
            ll w=e[i][0];
            ll u=e[i][1];
            ll v=e[i][2];

            join(u,v);
            if(len[find(0)]==n+1)
            {
                ans=w;
                break;
            }
        }
        cout << "Case #" << k << ": " << ans << "\n";
    }
    return 0;
}
