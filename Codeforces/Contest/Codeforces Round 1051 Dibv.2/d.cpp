#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
void sol()
{
    ll n;
    cin >> n;
    vector<ll> nums(n);
    for (ll i = 0; i < n; i++) cin >> nums[i];

    ll m = n + 1;
    vector<ll> dp(m * m, 0), clone(m * m, 0);
    dp[0] = 1;

    for (ll i : nums)
    {
        fill(clone.begin(), clone.end(), 0);
        for (ll j = 0; j <= n; j++)
        {
            for (ll nums = 0; nums <= n; nums++)
            {
                ll index = j * m + nums;
                ll c = dp[index];
                if (!c) continue;

                clone[index] = (clone[index] + c) % mod;

                bool checkright = (i>=j), checkleft = (i>= nums);

                if (checkright && checkleft)
                {
                    if (j >= nums) clone[i * m + nums] = (clone[i * m + nums] + c) % mod;
                    else clone[j * m + i] = (clone[j * m + i] + c) % mod;
                }
                else if (checkright)
                {
                    clone[i * m + nums] = (clone[i * m + nums] + c) % mod;
                }
                else if (checkleft)
                {
                    clone[j * m + i] = (clone[j * m + i] + c) % mod;
                }
            }
        }
        dp.swap(clone);
    }

    long long ans = 0;
    for (ll x : dp) ans = (ans + x) % mod;
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        sol();
    }
}
