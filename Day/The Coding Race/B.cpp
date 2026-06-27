#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int task;
    if (!(cin >> task)) return 0;

    string S;
    cin >> S;
    int n = S.length();

    if (task == 1) {
        int c26 = 0, c25 = 0;
        for (int i = 0; i <= n - 4; ++i) {
            if (n >= 4) {
                if (S.substr(i, 4) == "2026") c26++;
                if (S.substr(i, 4) == "2025") c25++;
            }
        }
        if (c26 > c25) cout << "YES\n";
        else cout << "NO\n";
    } else {
        if (n < 4) {
            cout << 0 << "\n";
            return 0;
        }

        vector<int> W(n, 0);
        for (int i = 3; i < n; i++) {
            if (S.substr(i - 3, 4) == "2026") W[i] = 1;
            else if (S.substr(i - 3, 4) == "2025") W[i] = -1;
        }

        vector<int> Pref(n, 0);
        Pref[0] = W[0];
        for (int i = 1; i < n; i++) Pref[i] = Pref[i - 1] + W[i];

        // BIT (Fenwick Tree) setup
        int OFFSET = n + 2;
        vector<int> bit(2 * n + 5, 0);

        auto add = [&](int idx, int val) {
            for (; idx < bit.size(); idx += idx & -idx) bit[idx] += val;
        };

        auto query = [&](int idx) {
            int sum = 0;
            for (; idx > 0; idx -= idx & -idx) sum += bit[idx];
            return sum;
        };

        long long ans = 0;
        for (int j = 3; j < n; j++) {
            // Thêm i = j - 1 (với i là L + 2)
            add(Pref[j - 1] + OFFSET, 1);

            // Tìm số lượng i sao cho Pref[j] > Pref[i]
            long long count = query(Pref[j] + OFFSET - 1);
            ans = (ans + count) % MOD;
        }
        cout << ans << "\n";
    }
    return 0;
}
