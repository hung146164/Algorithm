#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_multiset tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
using ll = long long;
#define all(v) v.begin(), v.end()
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define FOR_R(i, a, b) for (ll i = (a); i >= (b); --i)
#define each(x, v) for (auto x : v)
#define elif else if
#define len(v) (ll)(v).size()
template <class T>
using vi = vector<T>;
using pll = pair<int, int>;
template <class T>
using pq_max = priority_queue<T>;
template <class T>
using dq = deque<T>;
template <class T>
using pq_min = priority_queue<T, vector<T>, greater<T>>;
#define fi first
#define se second
#define pb push_back
#define el endl
template <class T>
istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v)
        in >> x;
    return in;
}
template <class T>
ostream& operator<<(ostream& out, const vector<T>& v) {
    for (auto& x : v)
        out << x << " ";
    return out;
}
template <class T, class U>
istream& operator>>(istream& in, pair<T, U>& p) {
    return in >> p.first >> p.second;
}
const ll mod = 1e9 + 7;
const ll MAX = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll get_rand(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(rng); }

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vi<ll> st_round, st_square;
    vi<bool> used(n, false);
    ll p0 = 0;
    FOR(i, 0, n) {
        if (s[i] == '(') {
            st_round.pb(i);
        } elif (s[i] == '[') {
            st_square.pb(i);
        } elif (s[i] == ')') {
            if (!st_round.empty()) {
                used[st_round.back()] = true;
                used[i] = true;
                st_round.pop_back();
                p0++;
            }
        } elif (s[i] == ']') {
            if (!st_square.empty()) {
                used[st_square.back()] = true;
                used[i] = true;
                st_square.pop_back();
                p0++;
            }
        }
    }
    vi<ll> rem_op, rem_cl;
    FOR(i, 0, n) {
        if (used[i]) continue;
        if (s[i] == '(' || s[i] == '[') {
            rem_op.pb(i);
        } else {
            rem_cl.pb(i);
        }
    }
    ll p1 = len(rem_op) / 2 + len(rem_cl) / 2;
    if (len(rem_op) % 2 == 1 && len(rem_cl) % 2 == 1) {
        if (rem_op.front() < rem_cl.back()) {
            p1++;
        }
    }
    cout << n - 2 * p0 - p1 << el;
}

int main() {
    fast();
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
