#include <bits/stdc++.h>

using namespace std;
const int N= 1e6+5;
int ar[N][26];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin>>n>>q;
    string s; cin>>s;
    for(int i=1; i<= n; i++)
    {
        for(int j=0; j< 26; j++)
        {
            ar[i][j]=ar[i-1][j]+(j==(s[i-1]-'a'));
        }
    }
    while(q--)
    {
        int a, b; cin>>a>>b;
        int cnt=0;
        for(int i=0; i<26; i++)
        {
            cnt+=(ar[b+1][i]-ar[a][i])%2==1?1:0;
        }
        cout<<cnt/2<<'\n';
    }
    return 0;
}
