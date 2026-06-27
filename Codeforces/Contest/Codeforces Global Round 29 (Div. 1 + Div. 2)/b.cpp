#include <bits/stdc++.h>
using namespace std;
void sol()
{
    int n;
    cin >> n;
    int m = 2 * n;
    vector<int> a(m + 1, 0),b(m+1,0);
    int curr = 1;
    for (int x = n; x >= 1; x--) {
        while (b[curr]) curr++;
        int l = curr;
        int r = l + x;
        while (r <= m && b[r]) r += x;
        a[l] = a[r] = x;
        b[l] = b[r] = 1;
    }
    for (int i = 1; i <= m; ++i) {
        cout<<a[i]<<' ';
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while (t--) {
        sol();
    }
    return 0;
}
