#include<bits/stdc++.h>
using namespace std;
void sol(int n, string& clone, int curr=0)
{
    if(curr==n)
    {
        cout<<clone<<'\n';
        return;
    }
    clone+='0';
    sol(n,clone,curr+1);
    clone.pop_back();

    clone+='1';
    sol(n,clone,curr+1);
    clone.pop_back();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin>>n;
    string clone="";
    sol(n,clone);
}
