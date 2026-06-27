#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int LOG = 61;
void sol()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> nums;
    ll start = 0;
    for (ll i = 0; i < n; i++)
    {
        ll x; cin>>x;
        nums.push_back(x);
        start |= nums[i];
    }

    ll MAXX = (1LL<<62);
    vector<ll> cost(LOG, MAXX);
    for (ll b = 0; b < LOG; b++)
    {
        ll can = 1LL << (b+1);
        ll diff = 1LL << b;
        for (ll i = 0; i < n; ++i)
        {
            ll x = nums[i];
            if ((x >> b) & 1)
            {
                cost[b] = 0;
            }
            else
            {
                ll du = x % can;
                ll need = diff - du;
                if (need < 0) need = 0;
                cost[b] = min(cost[b], need);
            }
        }
    }

    ll cou = __builtin_popcountll(start);

    vector<ll> ans;
    for (ll b = 0; b < LOG; b++)
    {
        if (((start >> b) & 1LL) == 0)
        {
            if (cost[b] < MAXX) ans.push_back(cost[b]);
        }
    }
    sort(ans.begin(), ans.end());

    vector<ll> prefix(ans.size() + 1, 0);
    for (ll i = 0; i < ans.size(); i++) prefix[i+1] = prefix[i] + ans[i];

    while (q--)
    {
        ll x;
        cin >> x;

        ll k = upper_bound(prefix.begin(), prefix.end(), x) - prefix.begin() - 1;
        cout << (cou + k) << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin>>t;
    while (t--)
    {
        sol();
    }

}
