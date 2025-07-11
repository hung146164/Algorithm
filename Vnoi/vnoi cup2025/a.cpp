#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        int n = s.size();

        bool found = false;
        for (int i = 0; i + 2 < n; ++i) {
            int cntU = 0, cntI = 0;
            for (int j = i; j < i + 3; ++j) {
                if (s[j] == 'U') ++cntU;
                else if (s[j] == 'I') ++cntI;
            }
            if ((cntU == 2 && cntI == 1) || (cntU == 1 && cntI == 2)) {
                cout << "Yes " << (i + 1) << " " << (i + 3) << "\n";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "No\n";
        }
    }
    return 0;
}
