#include<bits/stdc++.h>
using namespace std;
const int N=50001;
int parent[N],LEN[N];
void process()
{
    for(int i=0; i<N; i++)
    {
        parent[i]=i;
        LEN[i]=1;
    }
}
void mer(int a,int b)
{
    LEN[a]=LEN[a]+LEN[b];
    parent[b]=a;
}
int find(int u)
{
    if(u==parent[u])
    {
        return u;
    }
    return parent[u]=find(parent[u]);
}
void join(int a, int b)
{
    int pa=find(a);
    int pb=find(b);
    if(pa==pb) return;
    if(LEN[a]>LEN[b])
    {
        mer(pa,pb);
    }
    else
    {
        mer(pb,pa);
    }
}
bool check(int a,int b)
{
    return find(a)==find(b);
}
int main()
{
    int n,m,k;cin>>n>>m>>k;
    process();

    // skip
    for(int i=0; i< m ; i++)
    {
        int a, b; cin>>a>>b;
    }
    vector<pair<string,vector<int>>> q;
    while(k--)
    {
        string s;int a,b; cin>>s>>a>>b;
        q.push_back({s,{a,b}});
    }
    reverse(q.begin(),q.end());
    vector<bool> ans;
    for(int i=0; i< q.size(); i++)
    {
        string s=q[i].first;int a=q[i].second[0],b=q[i].second[1];
        if(s=="cut")
        {
            join(a,b);
        }
        else
        {
            ans.push_back(check(a,b)?1:0);
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto i: ans)
    {
        cout<<(i?"YES":"NO")<<'\n';
    }
}
