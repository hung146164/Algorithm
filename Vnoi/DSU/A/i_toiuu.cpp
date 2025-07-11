#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1;
int parent[N];
int kc[N];
void process(int n)
{
    for(int i=1; i<=n; i++)
    {
        parent[i]=i;
    }
}
int find(int u)
{
    if(u==parent[u])
    {
        return u;
    }
    int mp=find(parent[u]);
    kc[u]+=kc[parent[u]];
    return parent[u]=mp;
}
void mer(int a,int b)
{
    parent[a]=b;
    kc[a]=1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin>>n>>m;
    process(n);

    while(m--)
    {
        int x;cin>>x;
        if(x==1)
        {
            int a,b;cin>>a>>b;
            mer(a,b);
        }
        else{
            int a; cin>>a;
            find(a);
            cout<<kc[a]<<'\n';
        }
    }
}
