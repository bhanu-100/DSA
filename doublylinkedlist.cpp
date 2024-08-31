#include<iostream>
using namespace std;
class Node
{
    public:
    Node *prev;
    int data;
    Node *next;
};
class Linkedlist
{
  private:
  Node *first=NULL;
  public:
  Linkedlist(int A[],int n)
  {
    Node *t=NULL,*last=NULL;
    first=new Node;
    first->data=A[0];
    first->prev=NULL;
    first->next=NULL;
    last=first;
    for (int i=1;i<n;i++)
    {
        t=new Node;
        t->prev=NULL;
        t->data=A[i];
        t->next=NULL;
        last->prev =first;
        last->next=t;
        last=t;
    }
  }
  void Display();
  int length();
  void Insert(int index,int x);
  int Delete(int index);
};
void Linkedlist::Display()
{
    Node *p=first;
    while(p!=NULL)
    {
        cout<<p->data<<"  ";
        p=p->next;
    }
}
int Linkedlist::length()
{
    Node *p=NULL;
    p=first;
    int len=0;
     while(p!=NULL)
    {
        len++;
        p=p->next;
    }
    return len;
}
void Linkedlist::Insert(int index,int x)
{
  Node * p=first;
    Node *t=NULL;
    int i;
  if(index<0||index>length())
  return;
  if(index==0)
  {
    t=new Node;
    t->data=x;
    t->prev=NULL;
    t->next=first;
    first->prev=t;
    first=t;
  }
  else
  {
    for(i=0;i<index;i++)
    {
        p=p->next;
    }
    t=new Node;
    t->data=x;
    t->next=p->next;
    t->prev=p;
    if(p->next)
    p->next->prev=t;
    p->next=t;
  }
}
int Linkedlist::Delete(int index)
{
    Node *p=first;
    int i,x=0;
    if(index<1||index>length())
    return -1;
    if(index==1)
    {
        x=p->data;
        first=first->next;
        if(first)
        first->prev=NULL;
        delete p;
        return x;
    }
    else{
        for(i=1;i<index;i++)
        {
            p=p->next;
        }
        x=p->data;
        p->prev->next=p->next;
        if(p->next)
        p->next->prev=p->prev;
        delete p;
        return x;
    }
    return 0;
}
int main()
{
    int A[]={11,22,33,44,55,66,77};
    Linkedlist l(A,7);
    l.Display();
     l.Delete(2);
    l.Display();
    return 0;
}