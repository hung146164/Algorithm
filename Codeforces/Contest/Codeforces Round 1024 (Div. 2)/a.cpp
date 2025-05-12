#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n, m, p, q;
        cin >> n >> m >> p >> q;
        int k = n / p;
        int r = n % p;
        if (r == 0) {
            if (m == k * q)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }

    }
}
