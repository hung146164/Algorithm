#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;
const int LOG = 31;
int up[MAXN][LOG];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> up[i][0];  // next planet
    }

    // binary lifting precomputation
    for (int j = 1; j < LOG; ++j) {
        for (int i = 1; i <= n; ++i) {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<LOG; j++)
        {
            cout<<up[i][j]<<" ";
        }
        cout<<endl;
    }
    while (q--) {
        int a;
        long long k;
        cin >> a >> k;

        for (int i = 0; i < LOG; ++i) {
            if (k & (1LL << i)) {
                    cout<<a<<" "<<i<<endl;
                a = up[a][i];

            }
        }
        cout << a << '\n';
    }

    return 0;
}
