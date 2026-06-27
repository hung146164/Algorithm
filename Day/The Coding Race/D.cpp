#include <bits/stdc++.h>
using namespace std;

typedef __int128_t i128;

i128 n;
i128 best_S = -1;
i128 best_a = 0, best_b = 0, best_c = 0;

// Hàm cập nhật S nhỏ nhất
void update_best(i128 a, i128 b, i128 c) {
    if (a <= 0 || b <= 0 || c <= 0) return;

    i128 S = (a - n) * (a - n) + (b - n) * (b - n) + (c - n) * (c - n);

    // Nếu best_S chưa được gán (-1) hoặc tìm được S tốt hơn
    if (best_S == -1 || S < best_S) {
        best_S = S;
        best_a = a;
        best_b = b;
        best_c = c;
    }
}

// In kiểu số lớn
void print128(i128 val) {
    if (val == 0) { cout << 0; return; }
    string s;
    while (val > 0) {
        s += (char)('0' + (val % 10));
        val /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

int main() {
    // Tối ưu I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n_in;
    if (!(cin >> n_in)) return 0;
    n = n_in;

    // -----------------------------------------------------------------
    // PHẦN 1: Quét vét cạn mọi hình dáng Pytago gốc có kích thước nhỏ
    // Đảm bảo không bỏ sót các trường hợp n nhỏ và vừa.
    // -----------------------------------------------------------------
    for (long long u = 2; u <= 2000; u++) {
        for (long long v = 1; v < u; v++) {
            i128 A = (i128)u * u - (i128)v * v;
            i128 B = 2 * (i128)u * v;
            i128 C = (i128)u * u + (i128)v * v;

            i128 num = n * (A + B + C);
            i128 den = 2 * C * C;
            i128 k_opt = num / den;

            for (i128 dk = -2; dk <= 2; dk++) {
                i128 k = k_opt + dk;
                if (k > 0) {
                    update_best(k * A, k * B, k * C);
                    update_best(k * B, k * A, k * C);
                }
            }
        }
    }

    // -----------------------------------------------------------------
    // PHẦN 2: Dãy liên phân số của 1 + sqrt(2)
    // Dành cho các bộ Pytago có tỷ lệ hoàn hảo nhất.
    // -----------------------------------------------------------------
    vector<i128> U = {2, 5};
    vector<i128> V = {1, 2};
    while (true) {
        i128 next_u = 2 * U.back() + U[U.size() - 2];
        i128 next_v = 2 * V.back() + V[V.size() - 2];
        if (next_u > 2000000000LL) break;
        U.push_back(next_u);
        V.push_back(next_v);
    }
    for (size_t i = 0; i < U.size(); i++) {
        i128 u = U[i];
        i128 v = V[i];
        i128 A = u * u - v * v;
        i128 B = 2 * u * v;
        i128 C = u * u + v * v;

        i128 num = n * (A + B + C);
        i128 den = 2 * C * C;
        i128 k_opt = num / den;

        for (i128 dk = -2; dk <= 2; dk++) {
            i128 k = k_opt + dk;
            if (k > 0) {
                update_best(k * A, k * B, k * C);
                update_best(k * B, k * A, k * C);
            }
        }
    }

    // -----------------------------------------------------------------
    // PHẦN 3: Tìm kiếm lân cận tối ưu liên tục cho n CỰC LỚN (Sub 5 & 6)
    // Cố định hệ số k nhỏ, dò tìm các u, v lớn (phi liên phân số)
    // -----------------------------------------------------------------
    double n_d = (double)n_in;
    for (long long k = 1; k <= 100000; k++) {
        // Tính toán v lý tưởng từ đạo hàm (mẫu số là 4*sqrt(2))
        double v_opt = sqrt(n_d / (k * 5.656854249492380));
        long long start_v = max(1LL, (long long)v_opt - 5);
        long long end_v = (long long)v_opt + 5;

        for (long long v = start_v; v <= end_v; v++) {
            double u_opt = v * 2.414213562373095;
            long long start_u = max(v + 1LL, (long long)u_opt - 5);
            long long end_u = (long long)u_opt + 5;

            for (long long u = start_u; u <= end_u; u++) {
                i128 u128 = u;
                i128 v128 = v;
                i128 A = u128 * u128 - v128 * v128;
                i128 B = 2 * u128 * v128;
                i128 C = u128 * u128 + v128 * v128;
                i128 k128 = k;

                update_best(k128 * A, k128 * B, k128 * C);
                update_best(k128 * B, k128 * A, k128 * C);
            }
        }
    }

    // In kết quả cuối cùng
    print128(best_a); cout << " ";
    print128(best_b); cout << " ";
    print128(best_c); cout << "\n";

    return 0;
}
