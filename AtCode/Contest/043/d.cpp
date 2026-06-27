#include<bits/stdc++.h>
#define ll long long
#define en "\n"
#define inf 1e18
//cout << setprecision(7) << fixed
#define MOD 1000000007
using namespace std;
#define BIT(x, i) (((i) >> (x))&1)
#define find(s,a) s.find(a)!=s.end()
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin>>s;
    int n= s.size();
    for(int i=1 ;i<n; i++)
    {
        if(s[i]==s[i-1])
        {
            cout<<i<<' '<<i+1<<en;
            return 0;
        }
        if(i-2>=0 && s[i]== s[i-2])
        {
            cout<<i-1<<' '<<i+1<<en;
            return 0;
        }
    }
    cout<<-1<<' '<<-1<<en;
}

