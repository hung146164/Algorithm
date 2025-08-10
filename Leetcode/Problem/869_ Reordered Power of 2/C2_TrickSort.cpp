class Solution {
public:
    string tranfer(int n)
    {
        string s=to_string(n);
        sort(s.begin(),s.end());
        return s;
    }
    bool reorderedPowerOf2(int n) {
        string target=tranfer(n);
        int f=1;
        while(f<1e9)
        {
            if(target==tranfer(f)) return true;
            f<<=1;
        }
        return false;
    }
};