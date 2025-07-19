#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("word.in","r",stdin);
    freopen("word.out","w",stdout);

    int n,k;cin>>n>>k;
    int c=0;
    vector<string> cc;
    for(int i=0; i< n; i++)
    {
        string s;cin>>s;
        cc.push_back(s);
    }
    for(int i=0; i<cc.size(); i++)
    {
        c+=cc[i].size();
        if(c>k)
        {
            cout<<'\n';
            c=cc[i].size();
        }
        cout<<cc[i];
        if(i+1<cc.size())
        {
            if(cc[i+1].size()+c<=k) cout<<' ';
        }
    }
}



