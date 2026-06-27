// Problem C. Bạn có giỏi hóa học không?
#include <iostream>
#include <vector>

using namespace std;

int f[4];

int query(long long t1, long long t2, long long t3) {
    cout << "? " << t1 << " " << t2 << " " << t3 << "\n";
    cout.flush();
    int res;
    cin >> res;
    if (res == -1) exit(0);
    return res;
}

int main() {
    long long N;
    if (!(cin >> N)) return 0;

    long long low_val = -N - 1;
    long long high_val = N + 1;

    // Xác định hoán vị ẩn f
    int f0 = query(high_val, high_val, high_val);
    int f3 = query(low_val, low_val, low_val);
    int f1 = query(low_val, high_val, high_val);

    f[0] = f0;
    f[1] = f1;
    f[3] = f3;
    f[2] = 6 - f0 - f1 - f3;

    int inv[4];
    for (int i = 0; i < 4; i++) {
        inv[f[i]] = i;
    }

    // Tìm kiếm tứ phân (4-ary search)
    long long L = 0, R = N;
    while (L <= R) {
        if (R - L <= 2) {
            long long ans = L;
            for (long long k = R; k >= L; k--) {
                if (inv[query(k, k, k)] == 3) {
                    ans = k;
                    break;
                }
            }
            cout << "! " << ans << "\n";
            cout.flush();
            return 0;
        }

        long long step = (R - L + 1) / 4;
        long long m1 = L + step;
        long long m2 = L + 2 * step;
        long long m3 = L + 3 * step;

        int s = inv[query(m1, m2, m3)];
        if (s == 3) {
            L = m3;
        } else if (s == 2) {
            L = m2;
            R = m3 - 1;
        } else if (s == 1) {
            L = m1;
            R = m2 - 1;
        } else {
            R = m1 - 1;
        }
    }

    cout << "! " << L << "\n";
    cout.flush();
    return 0;
}
