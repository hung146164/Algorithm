#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

#define ALL(v)   (v).begin(), (v).end()
#define fi   first
#define se   second

template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        if (x > y) {
            x = y;
            return true;
        } else return false;
    }

template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        if (x < y) {
            x = y;
            return true;
        } else return false;
    }

const long long INF = (long long)1e14 + 2277;
const int MAX_ANSWER = (int)1e9 + 2277;

struct FenwickTree {
    vector<unsigned long long> bit;
    int n;

    FenwickTree(int _n = 0) {
        n = _n;
        bit.assign(n + 1, 0);
    }

    void reset(void) {
        REP(i, n + 1) bit[i] = 0;
    }

    void update(int x, long long d) {
        for (; x <= n; x += x & -x) bit[x] += d;
    }
    unsigned long long get(int x) const {
        unsigned long long res = 0;
        for (; x >= 1; x &= x - 1) res += bit[x];
        return res;
    }

    void updateRange(int l, int r, long long d) {
        update(l, d);
        update(r + 1, -d);
    }
};

struct Update {
    int node, value;
    long long delta;

    Update(int _node = 0, int _value = 0, long long _delta = 0) {
        node = _node; value = _value; delta = _delta;
    }

    bool operator < (const Update &u) const {
        return value < u.value;
    }
};

struct Query {
    int a, b, lck;
    long long budget;

    Query() {
        a = b = budget = 0;
    }

    void input(void) {
        scanf("%d%d%lld", &a, &b, &budget);
        minimize(budget, INF);
    }
};

struct Edge {
    int x, y, low, high, cost;

    Edge() {
        x = y = low = high = cost = 0;
    }

    void input(void) {
        scanf("%d%d%d%d%d", &x, &y, &low, &cost, &high);
    }

    long long getCost(int need) {
        if (need <= low) return 0;
        return need <= high ? cost : INF;
    }

    int other(int u) const {
        return x ^ y ^ u;
    }
};

#define MAX   100100
#define LOG   17

int numNode, numQuery;
vector<int> adj[MAX]; /// adj[u] = chi so cac canh ke voi dinh u
Edge edges[MAX];

void loadTree(void) {
    scanf("%d", &numNode);
    FOR(i, 1, numNode - 1) {
        edges[i].input();
        adj[edges[i].x].push_back(i);
        adj[edges[i].y].push_back(i);
    }

    scanf("%d", &numQuery);
}

namespace subtask1 {
    bool check(void) {
        return numNode <= 1000 && numQuery <= 1000;
    }

    int par[MAX], high[MAX]; /// par[u] = chi so canh noi giua dinh u va cha cua no

    void dfs(int u) {
        for (int i : adj[u]) if (i != par[u]) {
            int v = edges[i].other(u);
            par[v] = i;
            high[v] = high[u] + 1;
            dfs(v);
        }
    }

    bool ok(int a, int b, long long budget, int need) {
        if (high[b] > high[a]) swap(a, b);
        while (high[a] > high[b]) {
            budget -= edges[par[a]].getCost(need);
            if (budget < 0) return false;
            a = edges[par[a]].other(a);
        }

        while (a != b) {
            budget -= edges[par[a]].getCost(need);
            budget -= edges[par[b]].getCost(need);
            if (budget < 0) return false;
            a = edges[par[a]].other(a);
            b = edges[par[b]].other(b);
        }

        return true;
    }

    int answerQuery(int a, int b, long long budget) {
        int L = 0, R = MAX_ANSWER;
        while (true) {
            if (L == R) return R;
            if (R - L == 1) return ok(a, b, budget, R) ? R : L;
            int M = (L + R) >> 1;
            if (ok(a, b, budget, M)) L = M; else R = M - 1;
        }
    }

    void process(void) {
        high[0] = -1;
        dfs(1);

        REP(faker, numQuery) {
            int a, b;
            long long budget; scanf("%d%d%lld", &a, &b, &budget);
            printf("%d\n", answerQuery(a, b, budget));
        }
    }
}

namespace subtask3 {
    bool check(void) {
        return true;
    }

    Query queries[MAX];
    int parID[MAX], par[MAX][LOG + 1], high[MAX], sta[MAX], fin[MAX], cnt;
    int L[MAX], R[MAX];

    FenwickTree bit;

    void dfs(int u) {
        sta[u] = ++cnt;

        for (int i : adj[u]) {
            int v = edges[i].other(u);
            if (v == par[u][0]) continue;
            parID[v] = i;
            par[v][0] = u;
            high[v] = high[u] + 1;
            dfs(v);
        }

        fin[u] = cnt;
    }

    int lck(int u, int v) {
        if (high[v] > high[u]) swap(v, u);
        FORD(i, LOG, 0) if (high[par[u][i]] >= high[v]) u = par[u][i];
        if (u == v) return u;
        FORD(i, LOG, 0) if (par[u][i] != par[v][i]) {
            u = par[u][i]; v = par[v][i];
        }
        return par[u][0];
    }

    void prepare(void) {
        dfs(1);
        high[0] = -1;
        FOR(j, 1, LOG) FOR(i, 1, numNode) par[i][j] = par[par[i][j - 1]][j - 1];
    }

    void process(void) {
        prepare();

        FOR(i, 1, numQuery) {
            queries[i].input();
            queries[i].lck = lck(queries[i].a, queries[i].b);
        }
        FOR(i, 1, numQuery) {
            L[i] = 0; R[i] = MAX_ANSWER;
        }

        vector<Update> updates;
        FOR(u, 2, numNode) {
            int id = parID[u];
            updates.push_back(Update(u, edges[id].low + 1, edges[id].cost));
            updates.push_back(Update(u, edges[id].high + 1, INF));
        }
        sort(ALL(updates));

        bit = FenwickTree(numNode);

        while (true) {
            vector<pair<int, int>> checks;
            FOR(i, 1, numQuery) if (L[i] < R[i]) {
                int M = R[i] - L[i] == 1 ? R[i] : (L[i] + R[i]) >> 1;
                checks.push_back(make_pair(M, i));
            }
            if (checks.empty()) break;

            bit.reset();

            int j = 0;
            sort(ALL(checks));
            for (const pair<int, int> &ch : checks) {
                int curMid = ch.fi, curID = ch.se;

                while (j < (int)updates.size() && updates[j].value <= curMid) {
                    int tmp = updates[j].node;
                    bit.updateRange(sta[tmp], fin[tmp], updates[j].delta);
                    j++;
                }

                unsigned long long sumPath = bit.get(sta[queries[curID].a]) + bit.get(sta[queries[curID].b]) - 2 * bit.get(sta[queries[curID].lck]);
                if (sumPath <= queries[curID].budget) L[curID] = curMid; else R[curID] = curMid - 1;
            }
        }

        FOR(i, 1, numQuery) printf("%d\n", R[i]);
    }
}

int main(void) {
#ifdef SKY
    freopen("tmp.txt", "r", stdin);
#endif // SKY

    loadTree();
//    if (subtask1::check()) return subtask1::process(), 0;
    if (subtask3::check()) return subtask3::process(), 0;
    return 0;
}
