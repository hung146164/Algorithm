#include <bits/stdc++.h>
using namespace std;

int main() {
    long double n;
    cin >> n;

    if (n == 0 || n == 1) {
        cout << 1 << "\n";
        return 0;
    }

    const long double PI = acosl(-1.0L);
    const long double E  = expl(1.0L);

    long double x = n * log10(n / E) + 0.5L * log10(2.0L * PI * n);
    long long ans = (long long)floor(x + 1.0L);

    cout << ans << "\n";
    return 0;
}
