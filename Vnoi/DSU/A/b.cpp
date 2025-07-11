#include<bits/stdc++.h>
using namespace std;
const int MAXN=300001;
int parent[MAXN],LEN[MAXN],MI[MAXN],MA[MAXN];
int fin(int u)
{
    if(parent[u]==u)
    {
        return u;
    }
    return parent[u]=fin(parent[u]);
}
void Merge(int a,int b)
{
    MI[a]=min(MI[a],MI[b]);
    MA[a]=max(MA[a],MA[b]);
    LEN[a]=LEN[a]+LEN[b];
}
void uni(int a,int b)
{
    int pa=fin(a);
    int pb=fin(b);
   // cout<<pa<<" "<<pb<<endl;
    if(pa==pb) return;
    if(LEN[pa]<LEN[pb])
    {
        Merge(pb,pa);
        parent[pa]=pb;
    }
    else
    {
        Merge(pa,pb);
        parent[pb]=pa;
    }
}

vector<int> get(int a)
{
   int pa=fin(a);
   return {MI[pa],MA[pa],LEN[pa]};
}
void process()
{
    for(int i=0; i<MAXN; i++)
    {
        parent[i]=i;
        MI[i]=i;
        MA[i]=i;
        LEN[i]=1;
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
            int a; cin>>a;
            vector<int> ans=get(a);
            for(auto i: ans)
            {
                cout<<i<<" ";
            }
            cout<<'\n';
        }
    }

}
