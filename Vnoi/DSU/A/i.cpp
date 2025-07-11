#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1;
int parent[N];

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
        return 0;
    }
    return find(parent[u])+1;
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
            parent[a]=b;
        }
        else{
            int a; cin>>a;
            cout<<find(a)<<'\n';
        }
    }
}
