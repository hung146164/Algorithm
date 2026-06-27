#include <bits/bits/stdc++.h>
using namespace std;
int parent[1001];
int n;
void make_set()
{
    for(int i=0; i< n; i++)
    {
        parent[i]=i;
    }
}
void uni(int a,int b)
{
    int a=fin(parent(a));
    int b=fin(parent(b));
    if(a==b) return;


}
int fi(int v)
{
    if(v==parent[v])
        return v;
    return parent[v]=fi(parent[v]);
}
int main()
{
    cin>>n;

}
