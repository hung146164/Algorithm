#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        sort(a.begin(), a.end());

        map<int, int> freq; // đếm số topic đã có
        int cnt = 0; // số topic hiện có trong đoạn
        int l = 0, ans = INF;

        for (int r = 0; r < n; ++r) {
            int x = a[r];

            // Duyệt các ước của x
            for (int d = 1; d * d <= x; ++d) {
                if (x % d == 0) {
                    if (d <= m) {
                        if (++freq[d] == 1) cnt++;
                    }
                    int other = x / d;
                    if (other != d && other <= m) {
                        if (++freq[other] == 1) cnt++;
                    }
                }
            }

            while (cnt == m) {
                ans = min(ans, a[r] - a[l]);

                // Xóa a[l] khỏi cửa sổ
                int y = a[l];
                for (int d = 1; d * d <= y; ++d) {
                    if (y % d == 0) {
                        if (d <= m) {
                            if (--freq[d] == 0) cnt--;
                        }
                        int other = y / d;
                        if (other != d && other <= m) {
                            if (--freq[other] == 0) cnt--;
                        }
                    }
                }
                l++;
            }
        }

        cout << (ans == INF ? -1 : ans) << '\n';
    }
    return 0;
}
