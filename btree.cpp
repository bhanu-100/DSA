#include<iostream>
using namespace std;
#include<queue>
class Node
{
    public:
    Node *lchild;
    int data;
    Node* rchild;
};
class tree 
{
    private:
    queue<Node*> q;
    Node *root;
    public:
    void create();
     void preorder(Node *p);
    void preorder(){preorder(root);}
   void postorder(Node *p);
   void postorder(){postorder(root);}
   void inorder(Node *p);
   void inorder(){inorder(root);}
   void levelorder(Node *p);
   void levelorder(){levelorder(root);}
   int countnode(Node *p);
   int countnode(){countnode(root);}
   int sum(Node *p);
   int sum(){sum(root);}
   int leafnode(Node *p);
   int leafnode(){leafnode(root);}
   int height(Node *p);
   int height(){height(root);}
};
int tree::height(Node *p)
{
    int x=0,y=0;
    if(p==0)
    return 0;
    x=height(p->lchild);
    y=height(p->rchild);
    if(x>y)
    return x+1;
    else
    return y+1; 
}
void tree::create()
{
    root=new Node;
    Node *p,*t;
    int x=-1;
    cout<<"enter root value"<<endl;
    cin>>x;
    root->data=x;
    root->lchild=root->rchild=NULL;
    q.emplace(root);
    while(!q.empty())
    {
      p=q.front();
      q.pop();
      cout<<"enter left child"<<endl;
      cin>>x;
      if(x!=-1)
      {
        t=new Node;
        t->data=x;
        t->lchild=t->rchild=NULL;
         p->lchild=t;
         q.emplace(t);
      }
      cout<<"enter right child"<<endl;
      cin>>x;
      if(x!=-1)
      {
        t=new Node;
        t->data=x;
        t->lchild=t->rchild=NULL;
         p->rchild=t;
         q.emplace(t);
      }
    }
}
void tree ::preorder(Node *p)
{
    if(p!=NULL)
    {
      cout<<p->data<<"   ";
      preorder(p->lchild);
      preorder(p->rchild);
    }
}
void tree ::postorder(Node *p)
{
    if(p!=NULL)
    {
      postorder(p->lchild);
      postorder(p->rchild);
       cout<<p->data<<"   ";
    }
}
void tree ::inorder(Node *p)
{
    if(p!=NULL)
    {
      inorder(p->lchild);
      cout<<p->data<<"   ";
      inorder(p->rchild);
    }
}
void tree::levelorder(Node *p)
{
   queue<Node*> w;
   cout<<p->data<<"  ";
   w.emplace(p);
   while(!w.empty())
   {
    p=w.front();
    w.pop();
    if(p->lchild)
    {
        cout<<p->lchild->data<<"  ";
        w.emplace(p->lchild);
    }
    if(p->rchild)
    {
        cout<<p->rchild->data<<"  ";
        w.emplace(p->rchild);
    }
   }
}
int tree :: countnode(Node *p)
{
    int x,y;
    if(p!=NULL)
    {
        x=countnode(p->lchild);
        y=countnode(p->rchild);
        return x+y+1;
    }
    return 0;
}
int tree :: sum(Node *p)
{
    int x=0,y=0;
    if(p!=NULL)
    {
        x=sum(p->lchild);
        y=sum(p->rchild);
        return x+y+p->data;
    }
    return 0;
}
int tree :: leafnode(Node *p)
{
    int x=0,y=0;
    if(p!=NULL)
    {
        x=leafnode(p->lchild);
        y=leafnode(p->rchild);
        if(p->lchild==NULL&&p->rchild==NULL)
        return x+y+1;
        else 
        return x+y;
    }
    return 0;
}
int main()
{
    tree t;
    t.create();
    t.preorder();
    cout<<endl;
    t.postorder();
        cout<<endl;

    t.inorder();
        cout<<endl;

    t.levelorder();
        cout<<endl;

    cout<<t.countnode()<<endl;
   cout<< t.leafnode()<<endl;
    cout<<t.height()<<endl;
     cout<<t.sum();
    cout<<endl;

    return 0;
}