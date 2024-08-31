#include<iostream>
#include<stack>
using namespace std;
class Node
{
    public:
    Node *left;
    int data;
    Node *right;
};
class Tree
{
    public:
    Node *first,*p,*temp;
    void createtree(int x)
    {
      temp=new Node;
      temp->data=x;
      temp->right=temp->left=NULL;
      if(first==NULL)
      {
        first=temp;
      }
      p=first;
      while(p->left!=NULL||p->right!=NULL)
      {
        if(temp->data>p->data)
        {
            p=p->right;
        }
        else{
            p=p->left;
        }
      }
     if(temp->data>p->data)
        {
            p->right=temp;
        }
        else{
        p->left=temp;
        }
    }
  
};
int main()
{
Tree t1;
t1.createtree(5);
}