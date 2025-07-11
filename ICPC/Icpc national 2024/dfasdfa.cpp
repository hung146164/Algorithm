#include <bits/stdc++.h>
using namespace std;

// Giải A·x = b (mod 2) với A là m×k, b là m-vec, x là k-vec.
// A: vector< bitset<MAXK> > kích thước m,
// b: vector<int> kích thước m.
// Trả về false nếu vô nghiệm, true nếu có nghiệm (và x được ghi ra một nghiệm).
bool gauss_mod2(vector< bitset<10005> >& A, vector<int>& b, vector<int>& x, int m, int k) {
    vector<int> where(k, -1);
    int row = 0;
    for (int col = 0; col < k && row < m; ++col) {
        // tìm dòng pivot
        int sel = -1;
        for (int i = row; i < m; ++i) {
            if (A[i][col]) { sel = i; break; }
        }
        if (sel < 0) continue;
        swap(A[sel], A[row]);
        swap(b[sel], b[row]);
        where[col] = row;
        // triệt tiêu
        for (int i = 0; i < m; ++i) {
            if (i != row && A[i][col]) {
                A[i] ^= A[row];
                b[i] ^= b[row];
            }
        }
        ++row;
    }
    // kiểm tra vô nghiệm: có dòng 0 = 1 không?
    for (int i = row; i < m; ++i) {
        if (b[i]) return false;
    }
    // dựng nghiệm
    x.assign(k, 0);
    for (int col = 0; col < k; ++col) {
        if (where[col] != -1)
            x[col] = b[where[col]];
        // else để 0
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;

        // d[i] = 1 nếu muốn bit i cuối là 1, tức flip parity phải = (s[i]^1)
        vector<int> d(n);
        for (int i = 0; i < n; ++i)
            d[i] = ( (s[i]-'0') ^ 1 );

        // số biến = sum_{j=0..n-1} (số độ dài L khả dĩ)
        //          = n * (b - a + 1)  (ta vẫn cấp đủ)
        int K = n * (b - a + 1);

        // A là n×K
        vector< bitset<10005> > A(n);
        vector<int> bvec(n, 0);

        // Với mỗi vị trí i (dòng i), d[i] = sum x_{j,L} với
        //   j <= i <= j+L-1  và  a <= L <= b
        // biến x_{j,L} ta đánh chỉ số idx = j*(b-a+1) + (L-a).
        for (int i = 0; i < n; ++i) {
            bvec[i] = d[i];
            for (int j = 0; j < n; ++j) {
                // L phải sao cho j <= i <= j+L-1
                // ↔  L >= i-j+1  và  L <= b
                // lại còn L >= a.
                int minL = max(a, i - j + 1);
                int maxL = b;
                if (minL > maxL) continue;
                // L chạy từ minL..maxL
                for (int L = minL; L <= maxL; ++L) {
                    int idx = j * (b - a + 1) + (L - a);
                    A[i].set(idx);
                }
            }
        }

        vector<int> x;
        bool ok = gauss_mod2(A, bvec, x, n, K);
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
