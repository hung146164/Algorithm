#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll t;
    cin >> t ;
    while (t--) {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        vector<ll> a, b;
        for (ll i = 0; i < n; ++i) {
            if (s[i] == 'A') a.push_back(i + 1);
            else b.push_back(i + 1);
        }
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());

        bool ans = false;

        //constructive
        for (ll c : a) {
            if (c == 1 && b.size() == 1 && b[0]==n) {
                ans=true;
            }
            else if (c == n) {
                bool check=true;
                for(int i=0; i< b.size(); i++)
                {
                    if(b[i]==1)
                    {
                        check=false;
                        break;
                    }
                }
                if(check) ans=true;
            }
            else {
                bool check=true;
                for(int i=0; i< b.size(); i++)
                {
                    if(b[i] > c)
                    {
                        check=false;
                        break;
                    }
                }
                if(check) ans=true;
            }

            if (ans) break;
        }

        if(ans) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
}
