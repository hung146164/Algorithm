#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        int clone=x;
        int y=0;
        while(clone)
        {
            y+=clone%2;
            clone/=2;
        }
        //int y = __popcount(x); // Count of set bits in x

        if (n == 1 && y == 0) {
            cout << "-1\n";
        } else if (n < y) {
            cout << x << '\n';
        } else {
            int extra = (n - y);
            // If extra is even, we can add that directly
            if (extra % 2 == 0) {
                cout << x + extra << '\n';
            } else {
                // For odd extra, we need to adjust:
                // If x is 0 or 1, adding 1 might not increase popcount,
                // so add 3 to guarantee it.
                if (y <= 1) {
                    cout << x + extra + (x <= 1 ? 3 : 1) << '\n';
                } else {
                    cout << x + extra + 1 << '\n';
                }
            }
        }
    }

    return 0;
}
