#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long egcd(long long a, long long b, long long &x, long long &y){
    if(b==0){ x=1; y=0; return a; }
    long long x1,y1; long long g=egcd(b,a%b,x1,y1);
    x = y1; y = x1 - (a/b)*y1;
    return g;
}
long long modinv(long long k, long long p){
    long long x,y; egcd(k%p+p, p, x, y);
    x %= p; if(x<0) x += p;
    return x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    const vector<int> primes = {
        2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,
        101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199
    };
    while(t--){
        int n; long long k;
        cin >> n >> k;
        vector<long long> a(n);
        for(auto &x: a) cin >> x;

        long long p = -1;
        for(int q: primes){
            if((long long)q <= k+1 && (k % q != 0)){ p = q; break; }
        }
        if(p==-1){
            long long lim = min<long long>(k+1, 200000);
            vector<bool> isPrime(lim+1, true);
            isPrime[0]=isPrime[1]=false;
            for(long long i=2;i*i<=lim;i++) if(isPrime[i])
                for(long long j=i*i;j<=lim;j+=i) isPrime[j]=false;
            for(long long q=2;q<=lim;q++){
                if(isPrime[q] && k%q!=0){ p=q; break; }
            }
            if(p==-1) p=2;
        }

        long long invk = modinv(k % p, p);

        for(int i=0;i<n;i++){
            long long r = ((p - (a[i] % p + p) % p) * invk) % p;
            a[i] += r * k;
        }

        for(int i=0;i<n;i++){
            if(i) cout << ' ';
            cout << a[i];
        }
        cout << '\n';
    }
    return 0;
}
