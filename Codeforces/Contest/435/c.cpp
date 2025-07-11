#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> a{1,2,3,4,5,6,7};
    auto it=upper_bound(a.begin(),a.end(),0);
    if(it==a.begin()) cout<<"Yes";
}
