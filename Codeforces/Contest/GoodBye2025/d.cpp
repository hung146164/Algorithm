#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
const ll N=5e5+5;
const ll mod=1e9+7;
const ll modr=1e9+9;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll base=rng() % 500 +300;
ll powll(ll a, ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a%mod;
        }
        a=a*a%mod;
        b/=2;
    }
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll t; cin>>t;
    for(ll i_test=1;i_test<=t;i_test++)
    {
        ll n,m; cin>>n>>m;
        ll sum_all = 0;
        vector<ll> arr(n);
        vector<pair<ll,ll>>nums;
        for(ll i=0; i< n; i++)
        {
            cin>>arr[i];
            nums.push_back({arr[i],i});
            sum_all+=arr[i];
        }
        sort(nums.begin(), nums.end(),greater<pair<ll,ll>>());
        if (m == n)
        {
            if (n == 1) cout << 0 << el;
            else cout << -1 << el;
            continue;
        }

          if (n < 2 * m) { cout << -1 << el; continue; }
        vector<pair<ll,ll>> ans;
        if(m==1)
        {
            for(int i=n-1; i>=1; i--)
            {
                ans.push_back({nums[i].second,nums[i-1].second});
            }
        }
        else if(m==0)
        {

            if (n == 2) { cout << -1 << el; continue; }


            ll a = nums[0].first;
            ll b = nums[1].first;
            ll c = nums[0].second;
            ll d = nums[1].second;

            if (sum_all - a < a) { cout << -1 << el; continue; }
            ll tgt = a - b;
            ll s = 0;
            ll p = n - 1;
            while (p >= 2 && s < tgt) {
                ans.push_back({nums[p].second, c});
                s += nums[p].first;
                p--;
            }
            if (p >= 2) {
                for (ll i = p; i > 2; i--) {
                    ans.push_back({nums[i].second, nums[i-1].second});
                }

                ans.push_back({nums[2].second, d});
            }
            ans.push_back({d, c});
        }
        else {

            vector<vector<ll>> group(m);
            for(ll i=n-1; i>= m;i--) {
                group[(n-1-i)%m].push_back(nums[i].second);
            }
            for(ll i = 0; i < m; i++) {

                vector<ll> &g = group[i];

                for(ll j=0;j<g.size()-1;j++) {
                    ans.push_back({g[j],g[j+1]});
                }
                ans.push_back({nums[i].second, g.back()});
            }
        }
        //cout<<"TEST "<<i_test<<el;
        cout<<ans.size()<<el;
        for(ll i=0; i< ans.size(); i++)
        {
            cout<<ans[i].first+1<<' '<<ans[i].second+1<<el;
        }


    }
}



