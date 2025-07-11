#include <bits/stdc++.h>
using namespace std;
static const int MOD = 998244353, G = 3;

// fast exponentiation
int modexp(int a, int e=MOD-2){
    long long r=1, x=a;
    while(e){
        if(e&1) r=r*x%MOD;
        x=x*x%MOD;
        e>>=1;
    }
    return (int)r;
}

// NTT in-place on a[], n must be power of two
void ntt(vector<int>& a, bool invert){
    int n = a.size();
    static vector<int> rev;
    static vector<int> roots{0,1};
    if ((int)rev.size() != n) {
        rev.assign(n,0);
        for(int i=0;i<n;i++)
            rev[i] = (rev[i>>1]>>1) | ((i&1)?n>>1:0);
    }
    if ((int)roots.size() < n) {
        while ((int)roots.size() < n) {
            int k = roots.size();
            // root^( (MOD-1) / (2*k) )
            int e = modexp(G, (MOD-1)/(2*k));
            for(int i=k;i<2*k;i++)
                roots.push_back( (long long)roots[i-k] * e % MOD );
        }
    }
    for(int i=0;i<n;i++)
        if(i<rev[i]) swap(a[i],a[rev[i]]);
    for(int len=1;len<n;len<<=1){
        for(int i=0;i<n;i+=2*len){
            for(int j=0;j<len;j++){
                int u = a[i+j];
                int v = (long long)a[i+j+len] * roots[len+j] % MOD;
                a[i+j] = u+v < MOD ? u+v : u+v-MOD;
                a[i+j+len] = u-v >= 0 ? u-v : u-v+MOD;
            }
        }
    }
    if(invert){
        reverse(a.begin()+1, a.end());
        int inv_n = modexp(n);
        for(int &x:a) x = (long long)x * inv_n % MOD;
    }
}

// multiply two polynomials
vector<int> multiply(vector<int> a, vector<int> b){
    int need = a.size() + b.size() - 1;
    int nbase = 1;
    while(nbase < need) nbase <<= 1;
    a.resize(nbase);
    b.resize(nbase);
    ntt(a,false);
    ntt(b,false);
    for(int i=0;i<nbase;i++)
        a[i] = (long long)a[i] * b[i] % MOD;
    ntt(a,true);
    a.resize(need);
    return a;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n, k;
        string s;
        cin >> n >> k >> s;

        // Đếm tổng số 0 ban đầu
        vector<int> pref0(n+1,0);
        for(int i=0;i<n;i++){
            pref0[i+1] = pref0[i] + (s[i]=='0');
        }
        int z = pref0[n];

        // Xây P(x)
        // Tính Δ_i = i - 2*z_i
        // Chúng ta sẽ dịch exponent (i - 2*z_i) bằng cách shift mũ.
        // Nhưng để làm gọn, ta tìm minDelta để shift đa thức về chỉ số non-negative.
        int minD = INT_MAX, maxD = INT_MIN;
        vector<int> D(n);
        for(int i=1;i<=n;i++){
            int zi = pref0[i];
            int di = i - 2*zi;
            D[i-1] = di;
            minD = min(minD, di);
            maxD = max(maxD, di);
        }
        // shift = -minD để toàn bộ Δ_i + shift >= 0
        int shift = -minD;
        int deg = maxD - minD;

        // Tạo đa thức P với độ deg
        vector<int> P(deg+1, 0);
        for(int i=0;i<n;i++){
            P[ D[i] + shift ] = (P[ D[i] + shift ] + 1) % MOD;
        }

        // Lũy thừa đa thức: Q = P^k
        // Dùng binary exponentiation on polynomials
        vector<int> Q = {1};      // Q = 1
        vector<int> base = P;     // base = P
        int exp = k;
        while(exp){
            if(exp & 1)
                Q = multiply(Q, base);
            if(exp >>= 1)
                base = multiply(base, base);
        }

        // Hệ số x^{z + k*shift} trong Q chính là đáp án
        int idx = z + k*shift;
        int ans = 0;
        if(idx >= 0 && idx < (int)Q.size())
            ans = Q[idx];

        cout << ans << "\n";
    }
    return 0;
}
