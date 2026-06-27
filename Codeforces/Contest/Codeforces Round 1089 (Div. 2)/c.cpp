/*
    Author: HungForree
    Link:
*/

#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
const ll N=5e5+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
using i128 = __int128;
constexpr i64 inf = 1E18;

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
ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}


ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    for (ll i = 0; i < n; i++) cin >> b[i];


    vector<ll> uoc(n - 1);
    for (ll i = 0; i < n - 1; i++)
    {
        uoc[i] = gcd(a[i], a[i + 1]);
    }

    vector<ll> boi(n);
    boi[0] = uoc[0];
    boi[n - 1] = uoc[n - 2];
    for (ll i = 1; i < n - 1; i++)
    {
        boi[i] = lcm(uoc[i - 1], uoc[i]);
    }


    vector<vector<ll>> val(n);
    for (ll i = 0; i < n; i++)
    {

        ll cc = a[i] / boi[i];
        val[i].push_back(cc);

        ll right=(i<n- 1) ? (boi[i + 1] / uoc[i]) : 1;
        ll left=(i>0) ? (boi[i - 1] / uoc[i - 1]) : 1;
        ll candidate = b[i] / boi[i];

        auto ok = [&](ll x)
        {
            return gcd(x, left) == 1 && gcd(x, right) == 1;
        };


        if (candidate>= 1&& cc !=1 && ok(1))
        {
            val[i].push_back(1);
        }

        ll cnt = 0;
        for (ll v=2; v <=candidate; v++)
        {
            if (v ==cc) continue;
            if (ok(v))
            {
                val[i].push_back(v);
                cnt++;
                if (cnt >= 20) break;
            }
        }
    }


    vector<vector<ll>> dp(n);
    for (ll i = 0; i < n; i++)
    {
        dp[i].resize(val[i].size(), -1);
    }


    for (ll j = 0; j < val[0].size(); j++)
    {
        dp[0][j]=(val[0][j]==(a[0] / boi[0]) ? 0 : 1);
    }


    for (ll i = 1; i <n; i++)
    {
        for (ll j = 0; j <val[i].size(); j++)
        {
            ll cost = (val[i][j] == (a[i]/ boi[i])? 0 : 1);
            ll best = -1;

            for (ll k = 0; k < val[i - 1].size(); k++)
            {
                if (dp[i-1][k] != -1 && gcd(val[i- 1][k], val[i][j]) == 1)
                {
                    best = max(best, dp[i - 1][k]);
                }
            }

            if (best != -1)
            {
                dp[i][j] = best + cost;
            }
        }
    }


    ll ans = 0;
    for (ll j = 0; j < val[n - 1].size(); j++)
    {
        ans = max(ans, dp[n - 1][j]);
    }

    cout<<ans<<el;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}






