#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int parent[N],delta[N],total[N],LEN[N];

void process()
{
    for(int i=0; i<N; i++)
    {
        parent[i]=i;
        LEN[i]=1;
    }
    memset(total,0,sizeof(total));
    memset(delta,0,sizeof(delta));
}
int fin(int u)
{
    if(u==parent[u])
    {
        return u;
    }
    int p=parent[u];
    parent[u]=fin(p);
    delta[u]+=delta[p];
    return parent[u];
}
void mer(int a,int b)
{
    //cout<<a<<" "<<b<<endl;
    LEN[a]=LEN[a]+LEN[b];
    delta[b]=total[b]-total[a];
    parent[b]=a;
}
void join(int a, int b)
{
    int pa=fin(a);
    int pb=fin(b);
//    cout<<"pa "<<pa<<"pb "<<pb<<endl;
    if(pa==pb) return;
    if(LEN[pa]>LEN[pb])
    {
        mer(pa,pb);
    }
    else{
        mer(pb,pa);
    }

}
void add(int a, int val)
{
    int pa=fin(a);
    total[pa]+=val;
}
int get(int a)
{
    fin(a);
    return delta[a]+total[parent[a]];
}
//void Debug()
//{
//    for(int i=0; i<10; i++)
//    {
//        cout<<total[i]<<' ';
//    }cout<<endl;
//    for(int i=0; i< 10; i++)
//    {
//        cout<<delta[i]<<' ';
//    }
//    cout<<endl;
//}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    process();
    int n,m; cin>>n>>m;
    while(m--)
    {
        string s;cin>>s;
        if(s=="join")
        {
            int a,b;cin>>a>>b;
            join(a,b);
        }
        else if(s=="add")
        {
            int a,b; cin>>a>>b;
            add(a,b);
        }
        else{
            int a;cin>>a;
            cout<<get(a)<<'\n';
        }
//        Debug();

    }
}
