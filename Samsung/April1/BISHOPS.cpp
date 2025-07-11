#include<bits/stdc++.h>
using namespace std;
string add(string a, string b)
{
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());

    string ans="";
    int maxx=max(a.size(),b.size());
    int du=0;
    for(int i=0; i< maxx;i++ )
    {
        int h1=i<a.size()?a[i]-'0':0;
        int h2=i<b.size()?b[i]-'0':0;
        int t=h1+h2+du;
        if(t>9) du=1;
        else du=0;
        ans+=((t%10)+'0');
    }
    if(du==1) ans+='1';
    reverse(ans.begin(),ans.end());
    return ans;
}
string subtract(string a,string b)
{
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    string ans="";

    int maxx=max(a.size(),b.size());
    int du=0;
    for(int i=0; i< maxx;i++ )
    {
        int h1=i<a.size()?a[i]-'0':0;
        int h2=i<b.size()?b[i]-'0':0;
        int t=h1-h2-du;
        if(t<0)
        {
            du=1;
            t+=10;
        }
        else du=0;
        ans+=((t%10)+'0');
    }
    while(ans[ans.size()-1]=='0') ans.pop_back();
    reverse(ans.begin(),ans.end());
    return ans;
}
string sol(string n)
{

    if(n.size()==1 && n[0]-'0'<3)
    {
        return n;
    }

    return subtract(add(n,n),"2");
}
int main()
{

    string n;
    while (cin >> n) {
        cout << sol(n) << '\n';
    }
}
