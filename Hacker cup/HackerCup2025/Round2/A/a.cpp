#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("deciding_points_input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    if (!(cin >> t)) return 0;
    for (int k = 1; k <= t; ++k) {
        ll n, m;
        cin >> n >> m;
        string ans = "NO";
        if(n<m)
        {
            cout << "Case #" << k << ": " << ans << "\n";
            continue;
        }
        if(n-m<=m-2) ans="YES";
        else if( (n+2)%2==0 && (n+2)/2 >=m) ans="YES";

        cout << "Case #" << k << ": " << ans << "\n";
    }
    return 0;
}
