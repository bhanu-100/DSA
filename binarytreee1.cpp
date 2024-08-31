#include<iostream>
using namespace std;
class Node
{
    public:
    Node *lchild;
    int data;
    Node *rchild;
};
class Node1
{
    public:
    Node* data;
    Node1 *next;
};
class queue
{
   private:
   Node1 *front;
   Node1 *rear;
   public:
   queue()
   {
    front=NULL;
    rear=NULL;
   }
   void enqueue(Node* x);
   Node* dequeue();
   int isempty();
   int isfull();
   void Display();
};
int queue::isempty()
{
    if(front==NULL)
    return 1;
    else
    return 0;
}
int queue::isfull()
{
    Node1 *t=new Node1;
    if(t==NULL)
    return 1;
    else
    return 0;
}
void queue::enqueue(Node* x)
{
    Node1 *t=new Node1;
    if(t==NULL)
    cout<<"queue is full"<<endl;
    else
    {
        t->data=x;
        t->next=NULL;
        if(front==NULL)
        front=rear=t;
        else{
            rear->next=t;
            rear=t;
        }
    }
}
Node* queue::dequeue()
{
    Node* x=NULL;
  Node1 *p;
  p=NULL;
  if (front==NULL)
  cout<<"queue is empty"<<endl;
  else{
  p=front;
  front=front->next;
   x=p->data;
   delete p;
}
return x ;
}
void queue:: Display()
{
    Node1 *p;
    p=front;
    while(p!=NULL)
    {
        cout<<p->data<<"   ";
        p=p->next;
    }
    cout<<endl;
}
class tree
{
    private:
   Node *root=new Node;
   queue q;
   public:
   void create();
   void preorder();
   void postorder();
   void inorder();
   void levelorder();
   int countnode();
   int sum();
   int leafnode();
   int height();
};
void tree::create()
{
    Node *p,*t;
    int x;
    cout<<"enter root"<<endl;
    cin>>x;
    root->data=x;
    root->lchild=root->rchild=NULL;
    q.enqueue(root);
    while(!q.isempty())
    {
        p=q.dequeue();
        cout<<"enter the left child"<<p->data<<" : "<<endl;
        cin>>x;
         if(x!=-1)
         {
            t=new Node;
          t->data=x;
          t->lchild=t->rchild=NULL;
          p->lchild=t;
          q.enqueue(t);
         }
         cout<<"enter the right child"<<p->data<<" : "<<endl;
         cin>>x;
         if(x!=-1)
         {
            t=new Node;
          t->data=x;
          t->lchild=t->rchild=NULL;
          p->rchild=t;
          q.enqueue(t);
         }
    }
}
void tree::preorder()
{
    Node *t=new Node;
    t==root;
    if(t!=NULL)
    cout<<t->data<<"  ";
    t=t->lchild;
    preorder();
    t=t->rchild;
    preorder();
}
int main()
{
    tree t;
    t.create();
    t.preorder();
    return 0;
}