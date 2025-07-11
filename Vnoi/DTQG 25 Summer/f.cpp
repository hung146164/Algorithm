#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;cin>>n>>q;
    string s;cin>>s;

    vector<vector<int>> prefix(n+1,vector<int>(26));
    for(int i=1; i<= s.size(); i++)
    {
        for(int j=0; j<26; j++)
        {
            prefix[i][j]=prefix[i-1][j];
        }
        int index=s[i-1]-'a';
        prefix[i][index]=prefix[i-1][index]+1;
    }
    while(q--)
    {
        char c;cin>>c;
        int a,b; cin>>a>>b;
        cout<<prefix[b][c-'a']-prefix[a-1][c-'a']<<'\n';
    }
}
