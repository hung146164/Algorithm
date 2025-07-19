#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, a, b;
        cin >> n >> a >> b;

        // Điều kiện cơ bản: tổng thắng phải <= n
        if (a + b > n) {
            cout << "NO\n";
            continue;
        }

        int k = n - a - b;  // số lượt hòa

        multiset<int> S, Tset;
        for (int x = 1; x <= n; x++) {
            S.insert(x);
            Tset.insert(x);
        }

        vector<int> P, Q;
        P.reserve(n);
        Q.reserve(n);

        bool ok = true;
        // 1) k hòa
        for (int i = 0; i < k; i++) {
            int x = *S.begin();
            S.erase(S.begin());
            auto it = Tset.find(x);
            Tset.erase(it);
            P.push_back(x);
            Q.push_back(x);
        }
        // 2) a lượt P thắng
        for (int i = 0; i < a; i++) {
            if (S.empty() || Tset.empty()) { ok = false; break; }
            auto itP = prev(S.end());
            int p = *itP;
            S.erase(itP);

            int q = *Tset.begin();
            if (q >= p) { ok = false; break; }
            Tset.erase(Tset.begin());

            P.push_back(p);
            Q.push_back(q);
        }
        if (!ok) {
            cout << "NO\n";
            continue;
        }
        // 3) b lượt Q thắng
        for (int i = 0; i < b; i++) {
            if (S.empty() || Tset.empty()) { ok = false; break; }
            auto itP = S.begin();
            int p = *itP;
            S.erase(itP);

            auto itQ = Tset.upper_bound(p);
            if (itQ == Tset.end()) { ok = false; break; }
            int q = *itQ;
            Tset.erase(itQ);

            P.push_back(p);
            Q.push_back(q);
        }
        if (!ok || (int)P.size() != n) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for (int x : P) cout << x << ' ';
        cout << "\n";
        for (int x : Q) cout << x << ' ';
        cout << "\n";
    }
    return 0;
}
