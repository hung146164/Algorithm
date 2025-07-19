#include<bits/stdc++.h>
using namespace std;
int main()
{
//    freopen("teleport.in","r",stdin);
//    freopen("teleport.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a;
    for(int i=0; i< 7; i++)
    {
        int x; cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    cout<<a[0]<<' '<<a[1]<<' '<<a[6]-a[0]-a[1]<<'\n';


}



