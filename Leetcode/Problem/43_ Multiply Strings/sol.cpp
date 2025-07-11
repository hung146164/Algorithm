class Solution {
public:
    string muldigit(string s, int c)
    {
        reverse(s.begin(),s.end());
        string ans;
        int du=0;
        //cout<<s<<' '<<c<<endl;
        for(int i=0; i< s.size(); i++)
        {
            int a=s[i]-'0';
            int mul=a*c+du;
            //cout<<mul<<endl;
            du=mul/10;
            ans.push_back(mul%10+'0'); 
        }
        if(du) ans.push_back(du+'0');
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string add(string s,string t)
    {
        string ans;
        reverse(s.begin(),s.end());
        reverse(t.begin(),t.end());
        int du=0;
        for(int i=0; i<max(s.size(),t.size());i++)
        {
            int a=i<s.size()?s[i]-'0':0;
            int b=i<t.size()?t[i]-'0':0;
            int sum=a+b+du;
            du=sum/10;
            ans.push_back(sum%10+'0');
        }
        if(du) ans.push_back(du+'0');
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        string ans;
        for(int i=num2.size()-1;i>=0; i--)
        {
            string curr=muldigit(num1,num2[i]-'0')+string(num2.size()-1-i,'0');
            //cout<<curr<<endl;
            ans=add(ans,curr);
        }
        return ans;
    }
};