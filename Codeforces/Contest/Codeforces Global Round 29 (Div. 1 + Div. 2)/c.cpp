#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string sol() {
    ll n;cin>>n;
    string s; cin>>s;
    vector<ll> zero;
    for (ll i = 0; i < n; i++)
        { if (s[i] == '0') zero.push_back(i);}
    if (zero.size()==0) return "YES";

    vector<char> canleft(n, 0), canright(n, 0);
    for (ll i : zero) {
        //l
        bool l=false,r=false;
        if(i==0 || s[i-1]=='0') l=true;
        if(i>=2 && s[i-2]=='0') l=true;
        canleft[i]=l;
        //r
        if((i == n-1) || (s[i+1] == '0')) r=true;
        if(i+2<n && s[i+2]=='0') r=true;

        canright[i] = r;
    }

    ll m = zero.size();
    ll index = 0;
    while (index < m) {
        ll i = index;
        while (i + 1 < m && zero[i+1] == zero[i] + 2 && s[zero[i] + 1] == '1') i++;
        ll first = zero[index];
        ll curr = (canleft[first] ? 1 : 0) | (canright[first] ? 2 : 0);
        if (!curr) return "NO";
        for (ll j = index + 1; j <= i; j++) {
            ll i = zero[j];
            ll clone = 0;
            if ((curr & 1) && canright[i]) clone |= 2;
            if ((curr & 2) && canleft[i]) clone |= 1;
            curr = clone;
            if (!curr) return "NO";
        }
        index = i + 1;
    }
    return "YES";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin>>t;
    while (t--) {
        cout<<sol()<<'\n';
    }
    return 0;
}
