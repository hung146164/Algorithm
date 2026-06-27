/*
    Author: HungForree
    Link: https://codeforces.com/group/py59YCge5m/contest/678451/problem/E
*/

#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
const ll N = 2505; // Giới hạn n, k <= 2500
const ll mod = 998244353; // Đề bài yêu cầu modulo này
const ll modr = 1e9+9;

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

ll dp[N][N];
bool cache[N][N];
int n, k;

// sol(sum, y_prev): Tổng số substrings hiện tại, kích thước cụm y trước đó
ll sol(int sum = 0, int y_prev = 1) {
    if (sum == n) return 1; // Đạt đúng n substrings thì dừng (1 cách)
    if (sum > n) return 0;

    if (cache[sum][y_prev]) return dp[sum][y_prev];
    cache[sum][y_prev] = true;

    ll ans = 0;

    // Thử thêm một cụm số 0 mới (kích thước y_curr)
    // Điều kiện 1: y_prev + y_curr <= k + 1 (để substring lớn nhất <= k)
    for (int y_curr = 1; y_curr <= k + 1 - y_prev; ++y_curr) {
        // Điều kiện 2: Tổng substring mới không được vượt quá n
        if (sum + y_prev * y_curr <= n) {
            ans = (ans + sol(sum + y_prev * y_curr, y_curr)) % mod;
        } else {
            break; // y_curr tăng thì sum cũng chỉ tăng, break luôn cho tối ưu
        }
    }

    return dp[sum][y_prev] = ans;
}

void solve() {
    cin >> n >> k;

    // TRICK TRÁNH TLE: Chỉ clear mảng cache trong phạm vi n và k hiện tại.
    // Vì tổng n <= 2500, thao tác này cực kỳ nhẹ.
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= k + 1; ++j) {
            cache[i][j] = false;
        }
    }

    ll ans = 0;

    // Chọn kích thước cụm số 0 đầu tiên (y0)
    for (int y0 = 1; y0 <= k; ++y0) {
        ans = (ans + sol(0, y0)) % mod;
    }

    cout << ans << el;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
