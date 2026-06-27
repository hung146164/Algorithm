#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--)
    {
        int a, b; cin>>a>>b;
        int v=abs(a-b);
        bool found=false;
        int n=0;
        while(!found)
        {
            int candidate=n*(n+1)/2-v;
            if(candidate>=0 && candidate %2==0)
            {
                found=true;
                break;
            }
            n++;
        }
        cout<<n<<'\n';
    }
}


