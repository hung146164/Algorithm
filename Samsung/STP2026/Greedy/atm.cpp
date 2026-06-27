#include <iostream>

using namespace std;

// Precomputed arrays mapping digits 0-9 to their minimum notes and number of ways
int d_notes[10] = {0, 1, 1, 1, 2, 1, 2, 2, 2, 3};
int d_ways[10]  = {1, 1, 1, 1, 2, 1, 2, 1, 1, 3};

void solve() {
    long long W;
    int c;
    cin >> W >> c;

    // If W is not cleanly divisible by the smallest note, it's impossible
    if (W % 1000 != 0) {
        cout << 0 << "\n";
        return;
    }

    W /= 1000;
    long long N = 0; // Total minimum notes
    long long S = 1; // Total number of ways

    // Process each digit for the powers of 10 less than c
    for (int i = 0; i < c; ++i) {
        int d = W % 10;
        W /= 10;
        N += d_notes[d];
        S *= d_ways[d];
    }

    // Process the remaining overflow value V (which uses the highest 10^c denominations)
    long long V = W;
    if (V > 0) {
        long long q = V / 5;
        long long r = V % 5;

        if (r == 0) {
            N += q;
        } else if (r == 1) {
            N += q + 1;
            S *= (q == 0) ? 1 : 2;
        } else if (r == 2) {
            N += q + 1;
        } else if (r == 3) {
            N += q + 1;
        } else if (r == 4) {
            N += q + 2;
            S *= (q == 0) ? 2 : 3;
        }
    }

    cout << N << " " << S << "\n";
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
