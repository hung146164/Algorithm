#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int parent[N],len[N];
void process(int n)
{
    for(int i=0; i< n; i++)
    {
        parent[i]=i;
        len[i]=1;
    }
}
int fin(int n)
{
    if(parent[n]==n)
    {
        return n;
    }
    return parent[n]=fin(parent[n]);
}

void join(int a,int b)
{
    int pa=fin(a),pb=fin(b);
    if(pa==pb) return;

    if(len[pa]>len[pb])
    {
        parent[pb]=pa;
        len[pa]+=len[pb];
    }
    else{
        parent[pa]=pb;
        len[pb]+=len[pa];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin>>n;
    int m; cin>>m;
process(n);
    for(int i=0; i< m; i++)
    {
        int a,b;cin>>a>>b;
        a--;
        b--;
        join(a,b);
    }
    int ans=0;
    for(int i=0; i<n; i++)
    {
        ans=max(ans,len[i]);
    }
    cout<<ans<<'\n';

}

