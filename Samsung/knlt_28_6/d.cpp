#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+5;
const int mod=1e9+7;
struct Node
{
    string val="";
    Node* next{};
    Node* pre{};
    int cnt=0;
    Node(string val_,int cnt_=1)
    {
        this->val=val_;
        this->cnt=cnt_;
        next=nullptr;
        pre=nullptr;
    }
};
//a>b
bool cmp(string& a, string& b)
{
    for(int i=0; i< min(a.size(),b.size()); i++)
    {
        return a[i]>b[i];
    }
    return a.size()>b.size();
}
unordered_map<string,Node*> add;
void solve()
{
    int q; cin>>q;
    Node *head =new Node("",99999999);
    Node *tail= head;

    while(q--)
    {
        int a,b; cin>>a>>b;
        if(a==1)
        {
            for(int i=0; i< b; i++)
            {
                string s; cin>>s;
                if(add.find(s)==add.end())
                {
                    Node* nn=new Node(s);
                    tail->next=nn;
                    nn->pre=tail;
                    tail=tail->next;
                    add[s]=nn;

                    Node* curr=nn;

                    while((curr->pre->cnt<curr->cnt)|| (curr->pre->cnt==curr->cnt && cmp(curr->pre->val,curr->val)) )
                    {
                        Node* pre=curr->pre;

                        pre->next=curr->next;
                        if(curr->next!=nullptr) curr->next->pre=pre;

                        curr->pre=pre->pre;
                        curr->next=pre;
                        curr->pre->next=curr;
                        pre->pre=curr;
                    }




                }
                else{
                    Node* curr=add[s];
                    curr->cnt++;
                    while(curr->pre!=nullptr && ((curr->pre->cnt<curr->cnt)|| (curr->pre->cnt==curr->cnt && cmp(curr->pre->val,curr->val))) )
                    {
                        Node* pre=curr->pre;

                        pre->next=curr->next;
                        if(curr->next!=nullptr) curr->next->pre=pre;

                        curr->pre=pre->pre;
                        curr->next=pre;
                        curr->pre->next=curr;
                        pre->pre=curr;
                    }
                }
            }
        }
        else
        {
            Node* curr=head->next;
            for(int i=0; i<b && curr!=nullptr ;i++)
            {
                cout<<curr->val;;
                curr=curr->next;
                if(i!=b-1 && curr!=nullptr)
                {
                    cout<<", ";
                }
            }
            cout<<'\n';
        }
    }
//    Node* curr =head->next;
//    while(curr!=nullptr)
//    {
//        cout<<curr->val<<' '<<curr->cnt<<'\n';;
//        curr=curr->next;
//    }
}

signed main()
{
    solve();
}









