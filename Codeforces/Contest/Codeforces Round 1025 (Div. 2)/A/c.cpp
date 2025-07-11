#include <iostream>
using namespace std;

void solve() {
    long long m;
    cin >> m;

    cout << "mul 9" << endl;
    cout.flush();
    string r;
    cin >> r;
    if (r == "-1") return;

    cout << "digit" << endl;
    cout.flush();
    cin >> r;
    if (r == "-1") return;

    cout << "digit" << endl;
    cout.flush();
    cin >> r;
    if (r == "-1") return;

    cout << "add " << (m - 9) << endl;
    cout.flush();
    cin >> r;
    if (r == "-1") return;

    cout << "!" << endl;
    cout.flush();
    cin >> r;
    if (r == "-1") return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
