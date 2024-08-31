#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
};
class queue
{
   private:
   Node *front=new Node;
   Node *rear=new Node;
   public:
   queue()
   {
    front=NULL;
    rear=NULL;
   }
   void enqueue(int x);
   int  dequeue();
   bool isempty();
   bool isfull();
   void Display();
};
bool queue::isempty()
{
    if(front!=NULL)
    return false;
    else
    return true;
}
bool queue::isfull()
{
    Node *t=new Node;
    if(t==NULL)
    return true;
    else
    return false;
}
void queue::enqueue(int x)
{
    Node *t=new Node;
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
int queue::dequeue()
{
    int x=-1;
  Node *p=new Node;
  p=NULL;
  if (front==NULL)
  cout<<"queue is empty"<<endl;
  else{
  p=front;
  front=front->next;
   x=p->data;
   delete p;
}
return x;
}
void queue:: Display()
{
    Node *p=new Node;
    p=front;
    while(p!=NULL)
    {
        cout<<p->data<<"   ";
        p=p->next;
    }
    cout<<endl;
}
int main()
{
    queue q;
    q.enqueue(10);
    q.enqueue(11);
    q.enqueue(11);
    q.enqueue(11);
    q.enqueue(11);
    q.enqueue(11);
    q.Display();
    q.dequeue();
    q.Display();
    cout<<q.isempty();
    return 0;
}