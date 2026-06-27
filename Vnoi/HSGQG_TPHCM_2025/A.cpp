/*
    Author: HungForree
    Link: https://oj.vnoi.info/problem/hsg_hcm_v2_25_bando
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using i128 = __int128;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const int N = 1e6 + 5;
#define el '\n'

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int parent[N], len[N];
int find(int u)
{
    if (u == parent[u])
    {
        return u;
    }
    return parent[u] = find(parent[u]);
}
void join(int a, int b)
{
    int pa = find(a);
    int pb = find(b);
    if (pa == pb)
        return;
    parent[pa] = pb;
    len[pb] += len[pa];
}
void process(int n)
{
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
        len[i] = 1;
    }
}
void solve()
{
    int n, k;
    cin >> n >> k;
    process(n);

    int l = 0, r = n;

    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        int y = find(x);
        if (r - y >= y - l)
        {
            for (int j = 1; j <= y - l; j++)
            {
                join(y - j, y + j);
            }
            l = y;
        }
        else
        {
            for (int j = 1; j <= r - y; j++)
            {
                join(y + j, y - j);
            }
            r = y;
        }
    }
    cout << r - l + 1 << '\n';
    for (int i = l; i <= r; i++)
    {
        cout << len[find(i)] << ' ';
    }
}

int main()
{

    freopen("BANDO.INP", "r", stdin);
    freopen("BANDO.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}