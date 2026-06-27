#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
    // TXASDFZXCUV

    string s; cin>>s;
    int l=0,r=s.size()-1;
    while(l<s.size() && s[l]!='A')
    {
        l++;
    }
    while(r>=0 && s[r]!='Z')
    {
        r--;
    }
    if(r>l) cout<<r-l+1<<'\n';
    else cout<<0<<'\n';

}


