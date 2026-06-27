#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Kiểm tra khả thi cho t nhóm (t = number of top score groups to reward)
// g: vector số người ở từng group (theo score giảm dần), size >= t
// gifts: vector B_j (không cần sắp) - số units mỗi loại
bool check_with_pq(int t, const vector<ll> &g, const vector<ll> &gifts) {
    if (t == 0) return true;
    int m = (int)gifts.size();
    if (t > m) return false; // cần ít nhất t loại (distinct levels) minimal

    // tổng số người trong t nhóm
    ll totalPeople = 0;
    for (int i = 0; i < t; ++i) totalPeople += g[i];
    if (totalPeople == 0) return true;

    // build max-heap of capacities
    priority_queue<ll> pq;
    for (int i = 0; i < m; ++i) {
        if (gifts[i] > 0) pq.push(gifts[i]);
    }
    if (pq.empty()) return false;

    // We'll simulate rounds:
    // use block/c/val approach to compute how many people need in each successive round
    ll block = 0;
    ll c = g[0];
    ll val = t; // number of groups still needing in current round
    // r runs implicitly from 1 .. totalPeople, but we'll break early if impossible

    // For each "round" (one unit given to each of val people) we need to pop val distinct types
    // We'll pop val items from pq, decrement each by 1, collect back those >0.
    // Use a temp vector to store popped items to push back once per round (reduces PQ churn).
    while (true) {
        if (val == 0) break; // no more rounds needed
        // we must perform one round: give 1 unit to each of "val" people
        // Check if we have at least val distinct types available right now
        if ((ll)pq.size() < val) return false;

        vector<ll> temp;
        temp.reserve((size_t)val);
        for (ll i = 0; i < val; ++i) {
            ll top = pq.top();
            pq.pop();
            top -= 1;
            if (top > 0) temp.push_back(top);
        }
        // push back all reduced capacities
        for (ll x : temp) pq.push(x);

        // After performing one unit distribution to 'val' people, we reduce c and maybe block/val
        c--;
        if (c == 0) {
            block++;
            if (block < t) {
                c = g[block];
                val = t - block;
            } else {
                val = 0;
                c = 0;
            }
        }
        // loop continues until val==0 (all rounds done) or impossible
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("defining_prizes_input.txt","r",stdin); freopen("output.txt","w",stdout);
    int T;
    if (!(cin >> T)) return 0;
    for (int tc = 1; tc <= T; ++tc) {
        int n, m;
        cin >> n >> m;
        vector<ll> A(n);
        for (int i = 0; i < n; ++i) cin >> A[i];
        vector<ll> B(m);
        for (int j = 0; j < m; ++j) cin >> B[j];

        // sort scores desc and build groups
        sort(A.begin(), A.end(), greater<ll>());
        vector<ll> g; g.reserve(n);
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && A[j] == A[i]) ++j;
            g.push_back(j - i);
            i = j;
        }
        // binary search on number of groups t (prefix length of g)
        int maxGroups = (int)g.size();
        int L = 0, R = maxGroups;
        while (L < R) {
            int mid = (L + R + 1) / 2;
            if (check_with_pq(mid, g, B)) L = mid;
            else R = mid - 1;
        }
        // L groups feasible, answer = sum g[0..L-1]
        ll ans = 0;
        for (int i = 0; i < L; ++i) ans += g[i];

        cout << "Case #" << tc << ": " << ans << '\n';
    }
    return 0;
}
