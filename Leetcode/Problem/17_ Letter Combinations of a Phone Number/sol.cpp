class Solution {
public:
    void sol(vector<vector<char>>& hash,vector<string>& ans, string & digits,int curr,string& clone)
    {
        if(curr==digits.size())
        {
            ans.push_back(clone);
            return;
        }
        vector<char> key=hash[digits[curr]-'0'-2];
        for(auto i: key)
        {
            clone.push_back(i);
            sol(hash,ans,digits,curr+1,clone);
            clone.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="") return {};
        vector<vector<char>> hash{{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};

        vector<string> ans;
        string clone;
        sol(hash,ans,digits,0, clone);
        return ans;
    }
};