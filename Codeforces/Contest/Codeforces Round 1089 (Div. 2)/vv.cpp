#include <iostream>

using namespace std;


void print128(__int128_t n) {
    if (n == 0) {
        cout << 0;
        return;
    }
    string s = "";
    while (n > 0) {
        s = (char)('0' + (n % 10)) + s;
        n /= 10;
    }
    cout << s;
}

void solve() {
    int t;
    if (!(cin >> t)) return;

    for (int i = 1; i <= t; i++) {
        int k, n;
        cin >> k >> n;


        if (k > n - k) {
            k = n - k;
        }

        __int128_t result = 1;
        for (int j = 1; j <= k; j++) {
            result = result * (n - j + 1) / j;
        }

        cout << "#" << i << ": ";
        print128(result);
        cout << "\n";
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
