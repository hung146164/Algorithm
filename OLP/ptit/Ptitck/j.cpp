#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if(!(cin >> N)) return 0;
    vector<unsigned long long> A(N);
    unsigned long long maxA = 0;
    for(int i=0;i<N;i++){
        cin >> A[i];
        if(A[i] > maxA) maxA = A[i];
    }
    int digits = 1;
    {
        unsigned long long tmp = maxA;
        if(tmp == 0) digits = 1;
        else {
            digits = 0;
            while(tmp > 0){ tmp /= 10; digits++; }
        }
    }
    int D = digits + 1;
    vector<unsigned long long> pow10(D+2,1);
    for(int i=1;i<(int)pow10.size();++i) pow10[i] = pow10[i-1] * 10ULL;
    long long total = 0;
    for(int t = 0; t <= D; ++t){
        unsigned long long base = pow10[t];
        unsigned long long M = pow10[t+1];
        vector<unsigned long long> b(N);
        for(int i=0;i<N;i++) b[i] = A[i] % M;
        sort(b.begin(), b.end());
        for(int k = 0; k <= 19; ++k){
            unsigned long long low = (unsigned long long)k * base;
            unsigned long long high = (unsigned long long)(k+1) * base - 1ULL;
            long long pL = N-1, pR = N-1;
            long long count_pairs_k = 0;
            for(int i=0;i<N;i++){
                while(pL >= 0 && b[i] + b[pL] >= low) pL--;
                while(pR >= 0 && b[i] + b[pR] > high) pR--;
                long long cnt = pR - pL;
                if(cnt > 0) count_pairs_k += cnt;
            }
            if(count_pairs_k > 0){
                int digitVal = k % 10;
                total += 1LL * digitVal * count_pairs_k;
            }
        }
    }
    cout << total << "\n";
    return 0;
}
