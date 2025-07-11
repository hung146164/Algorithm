#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1000000007;
typedef long long ll;

ll modpow(ll a, ll e=MOD-2) {
    ll r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<vector<int>> query(t);
    int maxA = 0;
    for(int i = 0; i < t; i++){
        int a,b,k;
        cin >> a >> b >> k;
        query[i] = {a,b,k};
        maxA = max(maxA, a);
    }
    vector<ll> fact(maxA+1,1), ifact(maxA+1,1);
    for(int i = 1; i <= maxA; i++){
        fact[i] = fact[i-1] * i % MOD;
    }
    ifact[maxA] = modpow(fact[maxA]);
    for(int i = maxA; i > 0; i--){
        ifact[i-1] = ifact[i] * i % MOD;
    }
//    n(n−1)...(n−a+1)
//      chia
//      a!
    for(auto &tt : query){
        int a,b,k;
        a = tt[0];
        b=tt[1];
        k=tt[2];

        ll nn = ( (ll)(a-1) * k + 1 ) % MOD;

        ll big_n = (ll)(a-1) * k + 1;

        ll num = 1;
        for(int i = 0; i < a; i++){

            ll v = (big_n - i) % MOD;
            if(v < 0) v += MOD;
            num = num * v % MOD;
        }
        ll cccc = num * ifact[a] % MOD;

        ll m = ( (ll)(b-1) * k ) % MOD;
        m = ( m * cccc ) % MOD;
        m = (m + 1) % MOD;
        cout << nn << " " << m << "\n";
    }

    return 0;
}
