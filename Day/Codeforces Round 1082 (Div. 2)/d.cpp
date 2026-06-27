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
    int n, k;
    cin >> n >> k;

    if (k < n || k > 2 * n - 1) {
        cout << "NO" << el;
        return;
    }
    cout << "YES" << el;

    int m = k - n + 1;
    if (m == 1) {
        for (int i = 1; i <= n; i++) {
            cout << i << ' ' << i << ' ';
        }
        cout << el;
        return;
    }
    vector<int> ans;

    ans.push_back(1);
    ans.push_back(2);

    for (int i=1; i <=m-2; i++) {
        ans.push_back(i+2);
        ans.push_back(i);
    }

    ans.push_back(m-1);
    ans.push_back(m);

    for (int i = m + 1; i <= n; i++) {
        ans.push_back(i);
        ans.push_back(i);
    }

    for (auto& x : ans) {
        cout << x << ' ';
    }
    cout << el;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int t; cin >> t;
    while(t--)
    {
        solve();
    }
}
