class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> dp(26);

        for(int i=0; i< s.size(); i++)
        {
            dp[s[i]-'a']++;
        }
        int one=-1;
        for(int i=0; i< dp.size(); i++)
            {
                if(dp[i]%2==1)
                {
                    one=i;
                }
            }
        string ans="";
        for(int i=0; i< dp.size(); i++)
        {
            if(dp[i]>1)
            {
                ans+=string(dp[i]/2,'a'+i);
            }
        }
        string clone=ans;
        reverse(clone.begin(), clone.end());
        if(one!=-1)
        {
            ans+=one+'a';
        }
        return ans+clone;
    }
};
