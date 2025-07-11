#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int parent[N];
void process(int n)
{
    for(int i=1; i<=n; i++)
    {
        parent[i]=i;
    }
}
void change(int b)
{
    parent[b]=b+1;
}
int find(int b)
{

    if(parent[b]==-1) return -1;
    if(b==parent[b])
    {
        return b;
    }
    return parent[b]=find(parent[b]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin>>n>>m;
    memset(parent,-1,sizeof(parent));
    process(n);
    while(m--)
    {
        char a;int b; cin>>a>>b;
        if(a=='?')
        {
            cout<<find(b)<<'\n';
        }
        else
        {
            change(b);
        }
    }
}
