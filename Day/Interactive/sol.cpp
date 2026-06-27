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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    vector<long long> pref(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }

    int l = 1, r = n, ans = 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;

        int count = mid - l + 1;
        cout << "? " << count;
        for (int i = l; i <= mid; i++) {
            cout << " " << i;
        }
        cout << endl;

        long long actual_weight;
        cin >> actual_weight;

        long long expected_weight = pref[mid] - pref[l - 1];

        if (actual_weight > expected_weight) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << "! " << ans << endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int t; cin>>t;
    while(t--)
    {
        solve();
    }
}









