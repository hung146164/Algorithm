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
    if(parent[u]==u)
    {
        return u;
    }
    return parent[u]=find(parent[u]);
}
void change(int u,int p)
{
    parent[u]=p;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n;
    process(n);

    for(int i=0; i< n; i++)
    {
        int p; cin>>p;
        int chap=find(p);
        cout<<find(p)<<' ';
        change(chap,(chap==n?1:chap+1));
//        cout<<endl;
//        cout<<"cc"<<endl;;
//        for(int i=1; i<=n; i++) cout<<parent[i]<<' ';
//        cout<<"cc"<<endl;
//        cout<<endl;
    }

}
