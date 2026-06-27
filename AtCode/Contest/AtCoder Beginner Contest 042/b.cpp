#include<bits/stdc++.h>
#define ll long long
#define en "\n"
#define inf 1e18
//cout << setprecision(7) << fixed
#define MOD 1000000007
using namespace std;
#define BIT(x, i) (((i) >> (x))&1)
#define find(s,a) s.find(a)!=s.end()
bool cmp(string& a, string& b)
{
    for(int i=0; i< min(a.size(),b.size()); i++)
    {
        if(a[i]<b[i]) return a<b;
    }
    return a.size()<b.size();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,l; cin>>n>>l;
    vector<string> s;

    for(int i=0; i< n; i++)
    {
        string c; cin>>c;
        s.push_back(c);
    }
    sort(s.begin(),s.end(),cmp);
    for(auto& i : s) cout<<i;
}

