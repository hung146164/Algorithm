#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18+1 ;

ll sol() {
    int n;
    cin >> n;
    vector<vector<int>> hi(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> hi[i][j];
        }
    }
    vector<int> ca(n);
    for (int i = 0; i < n; ++i) {
        cin >> ca[i];
    }
    vector<int> cb(n);
    for (int i = 0; i < n; ++i) {
        cin >> cb[i];
    }
    vector<vector<vector<bool>>> fx(n - 1, vector<vector<bool>>(2, vector<bool>(2, false)));
    vector<vector<vector<bool>>> fy(n - 1, vector<vector<bool>>(2, vector<bool>(2, false)));
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n; ++j) {
            int df = hi[i][j] - hi[i + 1][j];
            if (df == 0) {
                fx[i][0][0] = true;
                fx[i][1][1] = true;
            } else if (df == 1) {
                fx[i][0][1] = true;
            } else if (df == -1) {
                fx[i][1][0] = true;
            }
        }
    }
    for (int j = 0; j < n - 1; ++j) {
        for (int i = 0; i < n; ++i) {
            int df = hi[i][j] - hi[i][j + 1];
            if (df == 0) {
                fy[j][0][0] = true;
                fy[j][1][1] = true;
            } else if (df == 1) {
                fy[j][0][1] = true;
            } else if (df == -1) {
                fy[j][1][0] = true;
            }
        }
    }
    vector<vector<ll>> dpx(n, vector<ll>(2, INF));
    dpx[0][0] = 0;
    dpx[0][1] = ca[0];
    for (int i = 1; i < n; ++i) {
        for (int pr = 0; pr < 2; ++pr) {
            if (dpx[i - 1][pr] >= INF) continue;
            for (int cu = 0; cu < 2; ++cu) {
                if (!fx[i - 1][pr][cu]) {
                    ll co = dpx[i - 1][pr] + (ll)cu * ca[i];
                    dpx[i][cu] = min(dpx[i][cu], co);
                }
            }
        }
    }
    ll bx = min(dpx[n - 1][0], dpx[n - 1][1]);
    if (bx >= INF) {
        return -1;
    }
    vector<vector<ll>> dpy(n, vector<ll>(2, INF));
    dpy[0][0] = 0;
    dpy[0][1] = cb[0];
    for (int j = 1; j < n; ++j) {
        for (int pr = 0; pr < 2; ++pr) {
            if (dpy[j - 1][pr] >= INF) continue;
            for (int cu = 0; cu < 2; ++cu) {
                if (!fy[j - 1][pr][cu]) {
                    ll co = dpy[j - 1][pr] + (ll)cu * cb[j];
                    dpy[j][cu] = min(dpy[j][cu], co);
                }
            }
        }
    }
    ll by = min(dpy[n - 1][0], dpy[n - 1][1]);
    if (by >= INF) {
        return -1;
    }

    return bx + by;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << sol() << endl;
    }
    return 0;
}
