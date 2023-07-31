#include<bits/stdc++.h>
using namespace std;


class TreeNode{

    public :
    int data;
    TreeNode* left = NULL;
    TreeNode* right = NULL;

    TreeNode(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }

};

TreeNode* buildTree(TreeNode* root)
{
     int data;
    cout<<"Enter the data for root ";
    cin>>data;

    root = new TreeNode(data);

    if(data == -1)
    {
        return NULL;
    }

    cout<<"Enter the data for inserting left of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter the data for inserting right of "<<data<<endl;
    root->right = buildTree(root->right);


    return root;

}

void inorder(TreeNode* root)
{
    if(root == NULL)
    {
        // cout<<"-1 ";
        return ;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(TreeNode* root)
{
    if(root == NULL)
    {
        // cout<<"-1 ";
        return ;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(TreeNode* root)
{
    if(root == NULL)
    {
        // cout<<"-1 ";
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}
int main()
{

    TreeNode* root = NULL;

    root = buildTree(root);

    inorder(root);
 return 0;
}