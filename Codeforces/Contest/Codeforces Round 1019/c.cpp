#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vi vector<int>
#define vll vector<ll>
#define fori(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll sz;
        ll  kv;

        cin >> sz >> kv;
        vll ar(sz);
        vi sg(sz);

        // tiền sử lý
        fori(i, sz) {
            cin >> ar[i];
            sg[i] = (ar[i] <= kv ? 1 : -1);
        }

        vi ps(sz + 1, 0);

        fori(i, sz) ps[i + 1] = ps[i] + sg[i];
        bool hg = (ps[1] >= 0);
        ll ts = ps[sz];
        ll ma = ps[1];
        ll mg = (ps[1] >= 0 ? ps[1] : INT_MAX);


        bool check  = false;
        fori(i, sz - 2) {
            ll p = i + 2;
            ll cs = ps[p];
            //thử tach pre va  sufix
            if ((hg && mg <= cs)  || (ma <= cs && cs <= ts)|| (hg && cs <= ts)) {
                check = true;
                break;
            }

            ma = min(ma, cs);
            if (cs >= 0) {
                if (!hg || cs < mg) mg = cs;
                hg = true;
            }
        }

        cout << (check ? "YES" : "NO") << '\n';
    }

    return 0;
}
