class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        set<vector<int>> ss;
        vector<bool> check(10,false);
        vector<int> clone;
        sol(ss,k,n,check,clone,1);
        vector<vector<int>> ans;
        for(auto i: ss)
        {
            ans.push_back(i);
        }
        return ans;
    }
    void sol(set<vector<int>>& ss, int k, int n, vector<bool>& check, vector<int>& clone,int pre)
    {
        if(n<0) return;
        if(n==0 && k==0)
        {

            ss.insert(clone);
            return;
        }
        else if(k==0) return;
        else if(n==0) return;

        for(int i=pre;i<=9 ; i++)
        {
            if(!check[i])
            {
                check[i]=true;
                clone.push_back(i);
                sol(ss,k-1,n-i,check,clone,i+1);
                clone.pop_back();
                check[i]=false;
            }
        }
    }

};
