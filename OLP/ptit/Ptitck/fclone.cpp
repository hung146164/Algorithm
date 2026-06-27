#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if(!(cin>>N)) return 0;
    vector<long long> cnt(9,0);
    for(int i=0;i<N;i++){
        long long a; cin>>a;
        cnt[a % 9]++;
    }
    long long res = 0;
    for(int r1=0;r1<9;r1++){
        for(int r2=0;r2<9;r2++){
            int s = (r1 + r2) % 9;
            int val = (s == 0 ? 9 : s);
            res += cnt[r1] * cnt[r2] * 1LL * val;
        }
    }
    cout << res << "\n";
    return 0;
}
