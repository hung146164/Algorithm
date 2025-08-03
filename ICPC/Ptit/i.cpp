#include<bits/stdc++.h>
using namespace std;

const int N = 61;
vector<vector<long long>> C(N, vector<long long>(N, 0));

void process() {
    for (int i = 0; i < N; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
            if (C[i][j] > (1LL<<63)-1)
                C[i][j] = (1LL<<63)-1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a, b;
    long long k;
    cin >> a >> b >> k;

    process();

    string ans = "";
    while (a > 0 || b > 0) {
        if (a == 0) {
            ans += 'b';
            b--;
        } else if (b == 0) {
            ans += 'a';
            a--;
        } else {
            long long cnt = C[a+b-1][a-1];
            if (k <= cnt) {
                ans += 'a';
                a--;
            } else {
                ans += 'b';
                k -= cnt;
                b--;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
