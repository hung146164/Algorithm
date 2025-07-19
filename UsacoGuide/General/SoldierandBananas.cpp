#include<bits/stdc++.h>
using namespace std;
int main()
{
//    freopen("teleport.in","r",stdin);
//    freopen("teleport.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

   int k,n,w;cin>>k>>n>>w;
    int sum=k*w*(w+1)/2-n;
   cout<<(sum<=0?0:sum)<<'\n';


}


