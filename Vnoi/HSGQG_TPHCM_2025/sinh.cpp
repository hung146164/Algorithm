#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long getRandom(long long l, long long r)
{
    uniform_int_distribution<long long> dist(l, r);
    return dist(rng);
}
int main()
{
    freopen("input.txt", "w", stdout);
    int n = 50000;
    int q = 10;
    cout << n << ' ' << q << '\n';
    for (int i = 0; i < n; i++)
    {
        cout << getRandom(0, 10) << ' ';
    }
    for (int i = 0; i < q; i++)
    {
        int a = getRandom(1, n);
        int b = getRandom(a, n);
        cout << a << ' ' << b << '\n';
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}