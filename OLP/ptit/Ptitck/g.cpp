#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;

vector<ll> fact, invfact;

ll modpow(ll a, ll e){
    ll r=1;
    while(e){
        if(e&1) r=r*a%MOD;
        a=a*a%MOD;
        e>>=1;
    }
    return r;
}

void precompute_fact(int n){
    fact.assign(n+1,1);
    invfact.assign(n+1,1);
    for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i%MOD;
    invfact[n]=modpow(fact[n], MOD-2);
    for(int i=n;i>0;i--) invfact[i-1]=invfact[i]*i%MOD;
}

inline ll P(int n,int k){
    if(k>n) return 0;
    return fact[n]*invfact[n-k]%MOD;
}

struct BIT{
    int n;
    vector<int> f;
    BIT(int n):n(n),f(n+1,0){}
    void update(int i,int v){ for(++i;i<=n;i+=i&-i) f[i]+=v; }
    int query(int i){ int s=0; for(++i;i>0;i-=i&-i) s+=f[i]; return s; }
    int range(int l,int r){ return query(r)-(l?query(l-1):0); }
};

struct Trie {
    struct Node {
        int id;
        array<int,26> nxt;
        Node(){ id=-1; nxt.fill(-1); }
    };
    vector<Node> tr;
    Trie(){ tr.emplace_back(); }
    void insert(const string &s,int id){
        int u=0;
        for(char c:s){
            int x=c-'a';
            if(tr[u].nxt[x]==-1){
                tr[u].nxt[x]=tr.size();
                tr.emplace_back();
            }
            u=tr[u].nxt[x];
        }
        tr[u].id=id;
    }
    void split(const string &s, vector<int>& ans){
        int u=0;
        for(int i=0;i<(int)s.size();i++){
            int x=s[i]-'a';
            u=tr[u].nxt[x];
            if(tr[u].id!=-1){
                ans.push_back(tr[u].id);
                u=0;
            }
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,K;
    cin>>N>>K;
    vector<string> arr(N);
    for(int i=0;i<N;i++) cin>>arr[i];

    vector<string> sorted = arr;
    sort(sorted.begin(),sorted.end());
    unordered_map<string,int> idx;
    idx.reserve(N*2);
    for(int i=0;i<N;i++) idx[sorted[i]]=i;

    Trie trie;
    for(int i=0;i<N;i++){
        trie.insert(arr[i], idx[arr[i]]);
    }

    string X; cin>>X;
    vector<int> perm;
    trie.split(X, perm);

    precompute_fact(N);

    BIT bit(N);
    for(int i=0;i<N;i++) bit.update(i,1);

    ll rank=0;
    for(int i=0;i<K;i++){
        int smaller = (perm[i]>0) ? bit.range(0, perm[i]-1) : 0;
        rank = (rank + 1LL*smaller*P(N-i-1, K-i-1)) % MOD;
        bit.update(perm[i], -1);
    }

    cout << (rank+1)%MOD << "\n";
}
