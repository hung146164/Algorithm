#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1;
int parent[N],LEN[N],nextx[N];

void process(int n)
{
    for(int i=1; i<=n; i++)
    {
        parent[i]=i;
        LEN[i]=1;
        nextx[i]=i+1;
    }
}
int fin(int u)
{
    if(u==parent[u]) return u;
    return parent[u]=fin(parent[u]);
}
void mer(int a,int b)
{
    LEN[a]=LEN[a]+LEN[b];
    parent[b]=a;
}
void join(int a,int b)
{
    int pa=fin(a);
    int pb=fin(b);
    if(LEN[pa]>LEN[pb])
    {
        mer(pa,pb);
    }
    else{
        mer(pb,pa);
    }
}
void muljoin(int a,int b)
{
    int i=a;
    while(i<=b)
    {
        int pa=fin(a);
        int pb=fin(i);
        if(pa!=pb)
        {
            if(LEN[pa]>LEN[pb]) mer(pa,pb);
            else mer(pb,pa);
        }
        int ni=nextx[i];
        nextx[i]=max(b+1,nextx[i]);
        i=ni;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;cin>>n>>m;
    process(n);
    while(m--)
    {
        int x,a,b; cin>>x>>a>>b;
        if(x==1)
        {
            join(a,b);
        }
        else if(x==2)
        {
            muljoin(a,b);
        }
        else{
            cout<<(fin(a)==fin(b)?"YES":"NO")<<'\n';
        }
//        for(int i=1; i<=8; i++) cout<<parent[i]<<' ';
//        cout<<endl;
    }
}
