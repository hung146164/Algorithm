class Solution {
public:
    void sol(set<int>& nums,vector<int>& pt,int bu,int num=0)
    {
        bool check=true;
        for(int i=0; i< pt.size(); i++)
        {
            if(!(pt[i]==0 || pt[i]==i))
            {
                check=false; 
                break;
            }
        }
        if(check) nums.insert(num);
        if(num>bu)
        {
            return;
        }
        for(int i=1;i<pt.size() ;i++)
        {
            if(pt[i])
            {
                pt[i]--;
                sol(nums,pt,bu,num*10+i);
                pt[i]++;
            }
        }
    }
    int nextBeautifulNumber(int n) {
        vector<int> pt(7);
        for(int i=0; i< pt.size(); i++)
        {
            pt[i]=i;
        }
        set<int> nums;
        for(auto i: nums) cout<<i<<' ';
        sol(nums,pt,n+1);
        return *nums.upper_bound(n);
    }
};