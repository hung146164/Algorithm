#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll sol(vector<ll>& h)
{
    ll n=h.size();

    ll total = 0;
    for (ll x : h) total += x;
    total -= (n - 1);
    ll a = 0, b = 0;
    for (ll i = 1; i < n; ++i) {
        ll w = min<ll>(i, h[i]) - 2;
        if (w < 0) w = 0;
        ll c = max(b, a + w);
        a = b;
        b = c;
    }
    return total - b;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin>>t;

    while (t--) {
        ll n;
        cin >> n;
        vector<ll> h(n);
        for (ll i = 0; i < n; ++i) {
                cin >> h[i];
            }
        cout << sol(h) << '\n';
    }

}
