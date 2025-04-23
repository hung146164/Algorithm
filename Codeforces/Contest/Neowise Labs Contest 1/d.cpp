#include <bits/stdc++.h>
using namespace std;
static const int INF = 1e9+7;
struct FW {
    int sz;
    vector<int> bit;
    bool mx;
    FW(){}
    FW(int n_, bool m): sz(n_), mx(m) {
        bit.assign(sz+1, m ? 0 : INF);
    }
    void u(int i, int v) {
        if (mx) for(; i<=sz; i+=i&-i) bit[i] = max(bit[i], v);
        else for(; i<=sz; i+=i&-i) bit[i] = min(bit[i], v);
    }
    int q(int i) const {
        int res = mx ? 0 : INF;
        for(; i>0; i-=i&-i)
            if (mx) res = max(res, bit[i]);
            else res = min(res, bit[i]);
        return res;
    }
};
struct ST2D {
    int na;
    int ln;
    vector<vector<int>> yv;
    vector<FW> fw;
    void init(int n_, vector<pair<int,int>>& ps) {
        na = n_;
        ln = 1; while(ln < na) ln <<=1;
        yv.assign(2*ln, {});
        for(auto &p: ps) {
            int a = p.first;
            int u = a + ln - 1;
            while(u>0) {
                yv[u].push_back(p.second);
                u >>= 1;
            }
        }
        fw.resize(2*ln);
        for(int u=1;u<2*ln;u++){
            auto &v = yv[u];
            sort(v.begin(), v.end());
            v.erase(unique(v.begin(), v.end()), v.end());
        }
    }
    void bld(bool useMx) {
        for(int u=1;u<2*ln;u++){
            int m = yv[u].size();
            fw[u] = FW(m, useMx);
        }
    }
    void uOne(int u, int b, int val){
        auto &v = yv[u];
        int pos = lower_bound(v.begin(), v.end(), b) - v.begin();
        if(pos == (int)v.size() || v[pos] != b) return;
        int ri = v.size() - pos;
        fw[u].u(ri, val);
    }
    void u(int a, int b, int val) {
        int u = a + ln - 1;
        while(u>0) {
            uOne(u, b, val);
            u >>= 1;
        }
    }
    int q(int A, int B) const {
        int res = fw[1].mx ? 0 : INF;
        int l = ln, r = A + ln - 1;
        while(l <= r){
            if(l&1){
                auto &v = yv[l];
                int pos = lower_bound(v.begin(), v.end(), B) - v.begin();
                if(pos < (int)v.size()){
                    int ri = v.size() - pos;
                    int qr = fw[l].q(ri);
                    if(fw[l].mx) res = max(res, qr);
                    else res = min(res, qr);
                }
                l++;
            }
            if(!(r&1)){
                auto &v = yv[r];
                int pos = lower_bound(v.begin(), v.end(), B) - v.begin();
                if(pos < (int)v.size()){
                    int ri = v.size() - pos;
                    int qr = fw[r].q(ri);
                    if(fw[r].mx) res = max(res, qr);
                    else res = min(res, qr);
                }
                r--;
            }
            l>>=1; r>>=1;
        }
        return res;
    }
};
struct ST1D {
    int sz;
    vector<int> st;
    void init(int n_){
        sz = n_;
        st.assign(4*sz+4, INF);
    }
    void u(int p, int l, int r, int i, int v){
        if(l==r){
            st[p] = min(st[p], v);
            return;
        }
        int m = (l+r)>>1;
        if(i<=m) u(p<<1, l, m, i, v);
        else u(p<<1|1, m+1, r, i, v);
        st[p] = min(st[p<<1], st[p<<1|1]);
    }
    int q(int p, int l, int r, int i, int j){
        if(r<i || j<l) return INF;
        if(i<=l && r<=j) return st[p];
        int m = (l+r)>>1;
        return min(q(p<<1, l, m, i,j),
                   q(p<<1|1, m+1, r, i,j));
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> x(m+1), a(m+1), b(m+1);
        for(int i=1;i<=m;i++) cin >> x[i] >> a[i] >> b[i];
        vector<pair<int,int>> zs;
        zs.reserve(m);
        for(int j=1;j<=m;j++) if(x[j]==0) zs.emplace_back(a[j], b[j]);
        ST2D sp;
        sp.init(n, zs);
        sp.bld(true);
        ST2D sn;
        sn.init(n, zs);
        sn.bld(false);
        vector<int> pc(m+1, 0), nc(m+1, INF);
        {
            for(int i=1;i<=m;i++){
                if(x[i]==1) pc[i] = sp.q(a[i], b[i]);
                else sp.u(a[i], b[i], i);
            }
        }
        {
            for(int i=m;i>=1;i--){
                if(x[i]==1) nc[i] = sn.q(a[i], b[i]);
                else sn.u(a[i], b[i], i);
            }
        }
        ST1D st;
        st.init(m);
        for(int i=1;i<=m;i++){
            if(x[i]==1){
                int p = pc[i];
                if(p>0) st.u(1,1,m,p,i);
                int q = nc[i];
                if(q<INF) st.u(1,1,m,i,q);
            }
        }
        int q;
        cin >> q;
        while(q--){
            int l, r;
            cin >> l >> r;
            int mn = st.q(1,1,m,l,r);
            cout << (mn <= r ? "NO\n" : "YES\n");
        }
    }
    return 0;
}
