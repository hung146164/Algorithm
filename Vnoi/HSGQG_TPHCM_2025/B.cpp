/*
    Author: HungForree
    Link: https://oj.vnoi.info/problem/hsg_hcm_v2_25_thaotac
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using i128 = __int128;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const int N = 5e4 + 5;
#define el '\n'

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long getRandom(long long l, long long r)
{
    uniform_int_distribution<long long> dist(l, r);
    return dist(rng);
}
int nums[N];
int n, q;
void sub2()
{
    vector<vector<ll>> val(11, vector<ll>(11));
    for (int i = 1; i < 11; i++)
    {
        for (int j = 1; j < 11; j++)
        {
            val[i][j] = i % j;
        }
    }
    vector<vector<ll>> cnt(n + 1, vector<ll>(11));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < 11; j++)
        {
            cnt[i][j] += cnt[i - 1][j];
        }
        cnt[i][nums[i]]++;
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        vector<int> curr(11);
        for (int j = 1; j < 11; j++)
        {
            curr[j] += cnt[r][j] - cnt[l - 1][j];
        }
        ll ans = 0;
        for (int j = 1; j < 11; j++)
        {
            for (int i = 1; i < 11; i++)
            {
                ans += val[i][j] * (curr[i] * curr[j]);
            }
        }
        cout << ans << '\n';
    }
}

void solve()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }
    if (n > 10000)
    {
        sub2();
    }
    else
    {
        vector<vector<ll>> p(n + 1, vector<ll>(n + 1));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                p[i][j] = nums[i] % nums[j];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                p[i][j] += p[i - 1][j];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                p[i][j] += p[i][j - 1];
            }
        }
        // cout << p.size() << ' ' << p[0].size() << '\n';
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            // cout << l << ' ' << r << endl;
            cout << p[r][r] - (p[l - 1][r] - p[l - 1][l - 1]) - p[r][l - 1] << '\n';
        }
    }
}

int main()
{
    // freopen("input.txt", "w", stdout);
    freopen("THAOTAC.INP", "r", stdin);
    freopen("THAOTAC.OUT", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;

    while (t--)
        solve();
    return 0;
}