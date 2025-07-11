#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int so(int n)
{
    int ans=0;
    while(n)
    {
        n/=2;
        ans++;
    }
    return ans;
}
int main()
{
    int t; cin>>t;
    while(t--)
    {
         ll n, m, a, b;
        cin >> n >> m >> a >> b;

        ll da = min(a, n - a + 1);
        ll db = min(b, m - b + 1);
        ll ch = 1 + ceil(log2(m)) + ceil(log2(da));
        ll cv = 1 + ceil(log2(n)) + ceil(log2(db));

         cout << min(ch, cv) << '\n';
    }
}
