#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("shuffle.in","r",stdin);
    freopen("shuffle.out","w",stdout);

    int n; cin>>n;
    vector<int> ans(n);
    vector<int> x1,x2;
    for(int i=0; i<n; i++)
    {
        int a;cin>>a;
        x1.push_back(a);
    }
    for(int i=0; i< n;i ++)
    {
        int a; cin>>a;
        x2.push_back(a);
    }
    for(int i=0; i< 3; i++)
    {
        for(int i=0; i< n; i++)
        {
            ans[i]=x2[x1[i]-1];
        }
        x2=ans;
    }
    for(int i=0; i< ans.size(); i++)
    {
        cout<<ans[i]<<'\n';
    }
}

