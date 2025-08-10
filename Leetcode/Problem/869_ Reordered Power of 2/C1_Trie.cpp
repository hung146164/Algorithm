class Node{
    public:
    vector<Node*> next;
    bool valid=false;
    Node()
    {
        next.resize(10);
    }
};

class Solution {
public:
    Node* mainnode;
    void init()
    {
        mainnode=new Node();
    }
    vector<int> getdigit(int n)
    {
        vector<int> ans;
        while(n)
        {
            ans.push_back(n%10);
            n/=10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    void build(int n)
    {
        vector<int> digit=getdigit(n);
        Node* curr=mainnode;
        for(int i=0;i<digit.size(); i++)
        {
            if(curr->next[digit[i]]==nullptr)
            {
                curr->next[digit[i]]=new Node();
            }
            curr=curr->next[digit[i]];
            if(i==digit.size()-1)
            {
                curr->valid=true;
            }
        }
    }
    bool sol(vector<int>& m,Node* currnode,bool first=true)
    {
        bool have=false;
        bool ans=false;
        if(first)
        {
            for(int i=1; i<10; i++)
            {
                if(m[i]>0) have=true;
                if(currnode->next[i]!=nullptr && m[i]>0)
                {
                    m[i]--;
                    ans|=sol(m,currnode->next[i],false);
                    m[i]++;
                }
            }
        }
        else{
            for(int i=0 ;i<10; i++)
            {
                if(m[i]>0) have=true;
                if(currnode->next[i]!=nullptr && m[i]>0)
                {
                    m[i]--;
                    ans|=sol(m,currnode->next[i],false);
                    m[i]++;
                }
            }
        }
        if(!have)
        {
            return currnode->valid;
        }
        return ans;
    }
    bool reorderedPowerOf2(int n) {
        init();
        int f=1;
        while(f<=1e9)
        {
            cout<<f<<'\n';
            build(f);
            f<<=1;
        }
        vector<int> m(10);
        while(n)
        {
            m[n%10]++;
            n/=10;
        }
        return sol(m,mainnode);
    }
};