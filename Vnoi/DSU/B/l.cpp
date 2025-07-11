#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int parent[N],LEN[N];

void process()
{
    for(int i=0; i< N ;i++)
    {
        parent[i]=i;
        LEN[i]=1;
    }
}
int fin(int u)
{
    if(u==parent[u]) return u;
    return parent[u]=fin(parent[u]);
}
void mer(int a, int b)
{
    LEN[a]+=LEN[b];
    parent[b]=a;
}
bool join(int a, int b)
{
    int pa=fin(a);
    int pb=fin(b);
    if(pa==pb) return false;

    if(LEN[pa]>LEN[pb])
    {
        mer(pa,pb);
    }
    else mer(pb,pa);
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    process();
    int n, m; cin>>n>>m;

    vector<vector<int>> e;

    for(int i=0; i< m ;i++)
    {
        int a,b,c; cin>>a>>b>>c;
        e.push_back({c,a,b});
    }
    sort(e.begin(),e.end());
    int ans=0;
    for(int i=0; i<e.size(); i++)
    {
        if(!join(e[i][1],e[i][2])) continue;
        ans=max(e[i][0],ans);
    }
    cout<<ans<<'\n';
}
