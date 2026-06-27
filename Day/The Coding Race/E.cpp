
#include <iostream>

using namespace std;

// Hàm nhân an toàn cho số lớn chống tràn (Subtask 6 MOD có thể lên 10^18)
long long mul(long long a, long long b, long long mod) {
    return (long long)((__int128_t)a * b % mod);
}

// Lũy thừa nhị phân an toàn
long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = mul(res, base, mod);
        base = mul(base, base, mod);
        exp /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m, MOD;
    while (cin >> n >> m >> MOD) {
        long long S = n * m;

        if (S == 1) {
            cout << 0 << "\n";
            continue;
        }

        // Công thức max score được chứng minh: Total = (S - 1) * (2^(S+2) - 4) % MOD
        long long part1 = (S - 1) % MOD;

        long long part2 = power(2, S + 2, MOD);
        part2 = (part2 - 4 + MOD) % MOD;

        long long ans = mul(part1, part2, MOD);
        cout << ans << "\n";
    }

    return 0;
}
