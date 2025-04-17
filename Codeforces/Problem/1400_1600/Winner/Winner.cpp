#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<pair<string,int>> a(n);
    unordered_map<string,int> mpp;
    for(int i=0;i<n;i++){
        string s;
        int t;
        cin>>s>>t;
        a[i]={s,t};
        mpp[s]+=t;
    }
    int maxi=INT_MIN;
    for(auto& it:mpp){
        if(it.second>maxi){
            maxi=it.second;
        }
    }
    unordered_map<string,int> curr;
    for(int i=0;i<n;i++){
        string& s=a[i].first;
        int t=a[i].second;
        curr[s]+=t;
        if(mpp[s]==maxi and curr[s]>=maxi){
            cout<<s<<endl;
            return 0;
        }
    }
    return 0;

    // system("pause");
}   