class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> fi(32,-2);
        vector<int> code(26,-1);
        code[0]=0;
        code['e'-'a']=1;
        code['i'-'a']=2;
        code['o'-'a']=3;
        code['u'-'a']=4;

        int mask=0;
        fi[0]=-1;
        int ans=0;
        for(int i=0; i< s.size(); i++)
        {
            int u=code[s[i]-'a'];
            if(u!=-1)
            {
                mask^=(1<<u);
            }
            if(fi[mask]==-2) fi[mask]=i;
            ans=max(ans,i-fi[mask]);
        }
        return ans;
    }
};