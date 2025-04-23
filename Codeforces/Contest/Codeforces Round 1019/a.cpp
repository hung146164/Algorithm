#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vs = vector<string>;

using si = set<int>;
using sll = set<ll>;
using mii = map<int, int>;
using mll = map<ll, ll>;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define f first
#define s second

int main()
{
    int t;cin>>t;
    while(t--)
    {

        int n ;cin>>n;
        unordered_map<int,int > dp;
        for(int i=0; i< n; i++)
        {
            int x ; cin>>x;
            dp[x]++;
        }
        cout<<dp.size()<<endl;
    }

}
