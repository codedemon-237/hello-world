#include<iostream>
using namespace std;

class Node {

public:
int data;
Node *left;
Node *right;
Node(){}
Node(int x)
{
  data = x;
  left = nullptr;
  right = nullptr;
}

};

class BST
{
  Node *root;
  Node* insertNode(int x,Node *root);
  Node* deleteNode(int x,Node *root);
  void preorder(Node *root);
  void inorder(Node *root);
  void postorder(Node *root);

  public:
  BST()
  {
    root = nullptr;
  }

  void Insert(int x);
  void Delete(int x);
  void pre_order();
  void in_order();
  void post_order();

};

void BST::Insert(int x)
{
   root = insertNode(x,root);
}

void BST::Delete(int x)
{
   root = deleteNode(x,root);
}

void BST::pre_order()
{
   preorder(root);
}

void BST::in_order()
{
   inorder(root);
}

void BST::post_order()
{
   postorder(root);
}

Node* BST::insertNode(int x,Node *root)
{
  if(root == nullptr)
  {
    root = new Node(x);
    return root;
  }
  else if(x <= root->data)
  {
     root->left = insertNode(x,root->left);
  }
  else
  {
     root->right = insertNode(x,root->right);
  }
}

Node* searchSmallest(Node *root,Node *parent)
{
   if(root == nullptr)
   return nullptr;

   if(root->left == nullptr){
   parent->right = root->right;
   root->right = nullptr;
   return root;
   }

   Node *ans = searchSmallest(root->left,root);
   return ans;
}


Node* BST::deleteNode(int x,Node* root){

    if(root == nullptr)
    return nullptr;

    if(root->data == x)
    {
       Node* temp = searchSmallest(root->right,root);
       if(temp != nullptr){
       temp ->left = root->left;
       temp ->right = root->right;
       }
       else
       {
          temp = root->left;
       }
       return temp;
    }
    else if(x < root->data)
    {
       root->left = deleteNode(x,root->left);
    }
    else
    {
       root->right = deleteNode(x,root->right);
    }
    return root;
}

void BST::preorder(Node *root)
{
   if(root == nullptr)
   return;

   cout<<root->data<<" ";
   preorder(root->left);
   preorder(root->right);
}

void BST::inorder(Node *root)
{
  if(root == nullptr)
   return;

  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

void BST::postorder(Node *root)
{
  if(root == nullptr)
   return;

  postorder(root->left);
  postorder(root->right);
  cout<<root->data<<" ";
}


int main()
{

BST *b = new BST();
cout<<"Press 1.Insert element in the tree"<<endl;
cout<<"      2.Delete element from the tree"<<endl;
cout<<"      3.Print the pre-order tree traversal"<<endl;
cout<<"      4.Print the in-order tree traversal"<<endl;
cout<<"      5.Print the post-order tree traversal"<<endl;
cout<<"      6.To exit"<<endl;
int ch;
cin>>ch;
int data;
while(ch != 6)
{

 switch(ch){

 case 1: cout<<"Enter the element"<<endl;
         cin>>data;
         b->Insert(data);
         break;
 case 2: cout<<"Enter the element"<<endl;
         cin>>data;
         b->Delete(data);
         break;
 case 3: cout<<"The preorder traversal looks like"<<endl;
         b->pre_order();
         break;
 case 4: cout<<"The inorder traversal looks like"<<endl;
         b->in_order();
         break;
 case 5: cout<<"The postorder traversal looks like"<<endl;
         b->post_order();
         break;
 case 6: exit(0);

 }
 cin>>ch;
}

return 0;
}
