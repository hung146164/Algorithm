#include<bits/stdc++.h>
using namespace std;
const int N= 1e3+1;
int arr[N];
vector<int> nt;
bool isnt(int n)
{
    for(int i=2; i*i<= n; i++)
    {
        if(n%i==0) return false;
    }
    return true;
}
void process()
{
    for(int i=2; i<=N; i++)
    {
        if(isnt(i))
        {
            nt.push_back(i);
        }
    }
}
void thuaso(int n)
{
    for(int i=0; i< nt.size() && n!=1; i++)
    {
        while(n%nt[i]==0)
        {
            n/=nt[i];
            arr[nt[i]]++;
        }
    }
}
int main()
{
    int n ; cin>>n;
    process();
    for(int i=1; i<=n; i++)
    {
        thuaso(i);
    }
    cout<<min(arr[2],arr[5])<<'\n';
}
