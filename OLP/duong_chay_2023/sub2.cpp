#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 MOD = 1000000007;

int64 mod_mul(int64 a, int64 b){ return (a%MOD)*(b%MOD)%MOD; }
int64 mod_add(int64 a, int64 b){ a%=MOD; b%=MOD; a+=b; if(a>=MOD) a-=MOD; return a; }
int64 mod_sub(int64 a, int64 b){ a%=MOD; b%=MOD; a-=b; if(a<0) a+=MOD; return a; }

int64 inv(int64 a){
    // MOD is prime
    int64 e = MOD-2, r=1;
    while(e){
        if(e&1) r = r*a % MOD;
        a = a*a % MOD;
        e >>= 1;
    }
    return r;
}

int64 C3_mod(int64 x, int64 inv6){
    if (x < 3) return 0;
    // x*(x-1)*(x-2)/6 mod
    int64 res = mod_mul(x % MOD, (x-1) % MOD);
    res = mod_mul(res, (x-2) % MOD);
    res = mod_mul(res, inv6);
    return res;
}

int n;
int Tval;
vector<int> weightv;
vector<vector<int>> adj;

int64 solve_allowed(const vector<char>& allowed){
    vector<char> vis(n+1, 0);
    vector<int> parent(n+1, 0), subtree(n+1, 0);
    int64 total_edges_cnt = 0; // sum over cnt_edge for all components

    int64 inv6 = inv(6);

    for(int s=1; s<=n; ++s){
        if(!allowed[s] || vis[s]) continue;
        // build component using iterative DFS, record parent and order
        vector<int> order;
        stack<int> st;
        st.push(s);
        vis[s]=1;
        parent[s]=0; // root marker
        while(!st.empty()){
            int u = st.top(); st.pop();
            order.push_back(u);
            for(int v: adj[u]){
                if(!allowed[v] || vis[v]) continue;
                vis[v] = 1;
                parent[v] = u;
                st.push(v);
            }
        }

        int m = (int)order.size();
        if(m < 3) continue; // no triples, contributes 0

        // compute subtree sizes: initialize 1, then process reverse(order)
        for(int u: order) subtree[u]=1;
        for(int i=(int)order.size()-1; i>=0; --i){
            int u = order[i];
            if(parent[u]!=0) subtree[parent[u]] += subtree[u];
        }

        int64 comb_m = C3_mod(m, inv6);
        int64 sum_cnt_edges = 0;
        for(int u: order){
            if(parent[u] != 0){
                int ssz = subtree[u];
                int64 term = comb_m;
                term = mod_sub(term, C3_mod(ssz, inv6));
                term = mod_sub(term, C3_mod(m - ssz, inv6));
                sum_cnt_edges = mod_add(sum_cnt_edges, term);
            }
        }
        // contribution of this component = 2 * sum_cnt_edges
        total_edges_cnt = mod_add(total_edges_cnt, mod_mul(2, sum_cnt_edges));
    }
    return total_edges_cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> Tval;
    weightv.assign(n+1,0);
    adj.assign(n+1, {});
    for(int i=1;i<=n;i++) cin >> weightv[i];
    for(int i=0;i<n-1;i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // allowed = all nodes
    vector<char> allowed_all(n+1, 1);
    int64 ans_all = solve_allowed(allowed_all);

    // allowed = nodes with weight == 1
    vector<char> allowed_w1(n+1, 0);
    for(int i=1;i<=n;i++) if(weightv[i]==1) allowed_w1[i]=1;
    int64 ans_w1 = solve_allowed(allowed_w1);

    int64 ans = 0;
    if(Tval == 1) ans = ans_w1;
    else if(Tval == 2) ans = mod_sub(ans_all, ans_w1);
    else ans = 0; // per problem only t in {1,2} for subtask2

    cout << ans % MOD << "\n";
    return 0;
}

