class Solution {
public:
    bool can(int p, int m, vector<int>& w, vector<int>& t,int st)
    {
        multiset<int> clone;
        for(int i=0; i< w.size(); i++) clone.insert(w[i]);
        //cout<<m+1<<" "<<r-l+1<<endl;
        for(int i=m; i>=0; i--)
        {
            auto it=clone.lower_bound(t[i]);
            if(it!=clone.end())
            {
                clone.erase(it);
                continue;
            }

            //
            if(p==0) return false;
            auto it2=clone.lower_bound(t[i]-st);
            if(it2==clone.end())
            {
                return false;
            }
            clone.erase(it2);
            p--;

            //return false;
        }
        return true;
    }
    int maxTaskAssign(vector<int>& t, vector<int>& w, int pills, int st) {
        sort(t.begin(), t.end());
        sort(w.begin(), w.end());
        int l = 0;
        int r = min(t.size(), w.size())-1;

        while (l <= r)
        {
            int m = l + (r - l) / 2;

            if (can(pills,m,w,t,st))
                l = m + 1;
            else
                r = m - 1;
        }

        return l;
    }
};
