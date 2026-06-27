#include<iostream>
#include<vector>
using namespace std;
const int N=1e5+5;

struct TreeNode
{
    int key, val;
    TreeNode* left,right,parent;
    //red=1, black=0;
    bool color;
    TreeNode()
    {
        left=NULL;
        right=NULL;
        parent=NULL;
        color=false;
    }
};

struct RedBlackTree
{
    TreeNode* root;
    TreeNode *NIL;
    RedBlackTree()
    {
        NIL = new TreeNode();
        NIL->color = false;
        NIL->left = NIL->right = NIL->parent = nullptr;
        NIL->data = 0;
        root=CreateNode;
    }
    RedBlackTree(vector<int>& nums)
    {
        build(nums);
    }
    TreeNode* CreateNode(int data)
    {
        TreeNode* node=new TreeNode();
        node->data= data;
        node->parent=node->left=node->right=NIL;
        node->color=true;
        return node;
    }
    void build(vector<int>& nums)
    {

    }
    void insert(int key,int val)
    {

    }
    void remove(int key)
    {

    }
    void search(int key)
    {
        return val;
    }
    void rotateleft(TreeNode* curr)
    {
        if(curr->right==NIL) return;
        TreeNode* right=curr->right;

        if(right->left!=NIL) right->left->parent=curr;
        curr->right=right->left;
        right->left=curr;
        if(curr->parent==NIL)
        {
            root=right;
        }
        else if(curr==curr->parent->left)
        {
            curr->parent->left=right;
        }
        else
        {
            curr->parent->right=right;
        }
        right->parent=curr->parent;
        curr->parent=right;
    }
    void rotateRight(TreeNode* curr)
    {
        if(curr->left==NIL) return;
        TreeNode* left=curr->left;

        if(left->right!=NIL) left->right->parent=curr;
        curr->left=left->right;
        left->right=curr;
        if(curr->parent==NIL)
        {
            root=left;
        }
        else if(curr==curr->parent->left)
        {
            curr->parent->left=left;
        }
        else
        {
            curr->parent->right=left;
        }
        left->parent=curr->parent;
        curr->parent=left;
    }
};

void rotation()
{

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


}
