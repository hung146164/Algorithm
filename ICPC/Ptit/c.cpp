
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 61; // vì A+B <=60
vector<vector<long long>> C(MAX, vector<long long>(MAX, 0));

// Hàm khởi tạo Pascal Triangle để tính tổ hợp
void initComb() {
    for (int i = 0; i < MAX; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
            if (C[i][j] > (1LL<<63)-1) // tránh tràn số 64bit
                C[i][j] = (1LL<<63)-1;
        }
    }
}

int main() {
    int A, B;
    long long K;
    cin >> A >> B >> K;

    initComb();

    string result = "";
    while (A > 0 || B > 0) {
        if (A == 0) {
            result += 'b';
            --B;
        } else if (B == 0) {
            result += 'a';
            --A;
        } else {
            long long cnt = C[A+B-1][A-1];
            if (K <= cnt) {
                result += 'a';
                --A;
            } else {
                result += 'b';
                K -= cnt;
                --B;
            }
        }
    }

    cout << result << endl;
    return 0;
}
