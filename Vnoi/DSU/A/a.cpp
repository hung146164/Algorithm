#include<bits/stdc++.h>
using namespace std;
const int MAXN=100001;
int parent[MAXN];
int fin(int u)
{
    if(parent[u]==u)
    {
        return u;
    }
    return parent[u]=fin(parent[u]);
}
void uni(int a,int b)
{
    int pa=fin(a);
    int pb=fin(b);
   // cout<<pa<<" "<<pb<<endl;
    if(pa==pb) return;
    parent[pa]=pb;
}

bool get(int a,int b)
{
   // cout<<fin(a)<<" "<<fin(b)<<endl;
    if(fin(a)==fin(b)) return true;
    return false;
}
void process()
{
    for(int i=0; i<MAXN; i++)
    {
        parent[i]=i;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    process();
    int n;cin>>n;
    int m;
    cin>>m;
    while(m--)
    {
        string s;cin>>s;
        if(s=="union")
        {
            int a,b;cin>>a>>b;
            uni(a,b);
        }
        else
        {
            int a, b; cin>>a>>b;
            cout<<(get(a,b)?"YES":"NO")<<'\n';
        }
    }

}
