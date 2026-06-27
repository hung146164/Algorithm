#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9 + 7;
map<vector<int>, vector<vector<long long>>> memo;

const int cost[4][4] = {
    {0, 1, 2, 1},
    {1, 0, 1, 2},
    {2, 1, 0, 1},
    {1, 2, 1, 0}
};

vector<long long> poly_add(const vector<long long>& p1, const vector<long long>& p2) {
    int n = max(p1.size(), p2.size());
    vector<long long> res(n);
    for (int i = 0; i < n; ++i) {
        long long v1 = (i < p1.size()) ? p1[i] : 0;
        long long v2 = (i < p2.size()) ? p2[i] : 0;
        res[i] = (v1 + v2) % MOD;
    }
    return res;
}

vector<long long> poly_shift(const vector<long long>& p, int k) {
    if (p.empty() || (p.size() == 1 && p[0] == 0)) return {0};
    vector<long long> res(p.size() + k, 0);
    for (int i = 0; i < p.size(); ++i) res[i + k] = p[i];
    return res;
}

vector<vector<long long>> solve(vector<int> counts) {
    if (memo.count(counts)) return memo[counts];

    int total = 0;
    for (int c : counts) total += c;
    if (total == 0) return {};

    if (total == 1) {
        vector<vector<long long>> res(4);
        for (int i = 0; i < 4; ++i) {
            if (counts[i] == 1) res[i] = {1};
            else res[i] = {0};
        }
        return memo[counts] = res;
    }

    vector<vector<long long>> res(4, {0});
    for (int last = 0; last < 4; ++last) {
        if (counts[last] > 0) {
            vector<int> prev_counts = counts;
            prev_counts[last]--;
            vector<vector<long long>> prev_res = solve(prev_counts);

            vector<long long> current_poly = {0};
            for (int prev_last = 0; prev_last < 4; ++prev_last) {
                int c = cost[prev_last][last];
                vector<long long> shifted_poly = poly_shift(prev_res[prev_last], c);
                current_poly = poly_add(current_poly, shifted_poly);
            }
            res[last] = current_poly;
        }
    }
    return memo[counts] = res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        vector<int> c(4);
        int n = 0;
        for (int i = 0; i < 4; ++i) {
            cin >> c[i];
            n += c[i];
        }
        memo.clear();
        vector<vector<long long>> result_polys = solve(c);

        vector<long long> final_poly = {0};
        for (int i = 0; i < 4; ++i)
            final_poly = poly_add(final_poly, result_polys[i]);

        for (int k = 0; k <= 2 * (n - 1); ++k) {
            if (k < final_poly.size()) cout << final_poly[k];
            else cout << 0;
            if (k != 2 * (n - 1)) cout << " ";
        }
        cout << "\n";
    }
    return 0;
}
