#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxN = 2e6 + 5;

int BIT[maxN];
int n, m, k;

void update(int i, int val)
{
    for (; i <= n; i += i & -i)
        BIT[i] += val;
}

int get(int i)
{
    int sum = 0;
    for (; i > 0; i -= i & -i)
        sum += BIT[i];
    return sum;
}

int col[maxN], row[maxN];
bool vis[maxN];
vector<int> point[maxN];

void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) row[i] = m + 1;
    for (int i = 1; i <= m; i++) col[i] = n + 1;

    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        point[y].push_back(x);
        row[x] = min(row[x], y);
        col[y] = min(col[y], x);
    }

    int res = 0;
    for (int i = 1; i < col[1]; i++)
        res += row[i] - 1;

    for (int i = col[1]; i <= n; i++)
    {
        update(i, 1);
        vis[i] = 1;
    }

    for (int y = 1; y < row[1]; y++)
    {
        res += get(col[y] - 1);
        for (int x : point[y])
        {
            if (!vis[x])
                update(x, 1);
            vis[x] = 1;
        }
    }

    cout << res;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int Case = 1;
    // cin >> Case;
    while (Case--)
        solve();
}
