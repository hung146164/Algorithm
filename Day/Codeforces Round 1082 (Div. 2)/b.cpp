/*
    Author: HungForree
    Link:
*/

#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
const ll N=1e6+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
using i128 = __int128;
constexpr i64 inf = 1E18;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int n;
string x;
int dp[N][2];
int cache[N][2];
int id=1;
char check(int bit) {
    return (bit == 0 ? 'a' : 'b');
}

bool sol(int curr, int bit)
{
    if(curr > n) return true;
    if(cache[curr][bit] ==id) return dp[curr][bit];
    cache[curr][bit]=id;
    int m = n - (curr - 1);
    int flip = (m - 1) & 1;
    char l = check(bit);
    char r = check(bit ^ flip);
    char need = x[curr - 1];

    bool ans = false;
    if (need == '?' || need == l) {
        if (sol(curr + 1, bit ^ 1)) ans = true;
    }
    if (!ans && (need == '?' || need == r)) {
        if (sol(curr + 1, bit)) ans = true;
    }

    return dp[curr][bit] = ans;
}

void solve()
{
    cin >> n >> x;
    if(sol(1, 0)) cout << "YES" << el;
    else cout << "NO" << el;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int t; cin>>t;
    while(t--)
    {
        solve();
        id++;
    }
}
