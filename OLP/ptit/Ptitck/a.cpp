#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;cin>>n>>q;
    string s; cin>>s;
    int ans=0;
    for(int i=2; i< s.size(); i++)
    {
        if(s.substr(i-2,3)=="ABC") ans++;
    }
    while(q--)
    {
        int x;cin>>x;
        x--;
        char c;cin>>c;
        if(n<3)
        {
            cout<<0<<'\n';
            continue;
        }
        for(int i=x-2;i<=x; i++)
        {
            if(i<0) continue;
            if(i+2<s.size())
            {
                if(s.substr(i,3)=="ABC") ans--;
            }
        }
        s[x]=c;
        for(int i=x-2;i<=x; i++)
        {
            if(i<0) continue;
            if(i+2<s.size())
            {
                if(s.substr(i,3)=="ABC") ans++;
            }

        }
        cout<<ans<<'\n';
    }
}

