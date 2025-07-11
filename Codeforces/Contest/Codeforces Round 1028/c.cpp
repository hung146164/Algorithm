#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int myGcd(int a, int b) {
    if(a%b==0) return b;
    return myGcd(b,a%b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int mingdc = a[0];
        for (int i = 1; i < n; i++) {
            mingdc = myGcd(mingdc, a[i]);
        }

        int sameg = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == mingdc) sameg++;
        }
        if (sameg > 0) {
            cout << (n - sameg) << "\n";
            continue;
        }

        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            b[i] = a[i] / mingdc;
        }

        sort(b.begin(), b.end());
        int m = b.size();

        unordered_map<int,int> d;

        queue<int> q;
        for (int i = 0; i < m; i++) {
            int v = b[i];
            if (d.find(v) == d.end()) {
                d[v] = 1;
                q.push(v);
            }
        }

        int k = -1;
        while (!q.empty()) {
            int x = q.front(); q.pop();
            int c = d[x];
            if (x == 1) {
                k = c;
                break;
            }
            for (int j = 0; j < m; j++) {
                int y = myGcd(x, b[j]);
                auto it = d.find(y);
                if (it == d.end() || it->second > c + 1) {
                    d[y] = c + 1;
                    q.push(y);
                }
            }
        }

        if (k == -1) {
            k = n;
        }

        ll ans = 1LL*n + k - 2;
        cout << ans << '\n';
    }

    return 0;
}
