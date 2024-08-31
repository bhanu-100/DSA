#include<iostream>
using namespace std;
class Node
{
public:
int data;
Node *next;
};
class Linkedlist
{
  private:
  Node *head=NULL;
  public:
  Linkedlist()
  {
   head=new Node;
  }
  void create(int A[],int n);
  void Display();

};
void Linkedlist::create(int A[],int n)
{
    Node *p=NULL;
    Node *last=NULL;
   
    head->data=A[0];
    head->next=NULL;
    last=head;
    for(int i=1;i<n;i++)
    {
         p=new Node;
       p->data=A[i];
       p->next=last->next;
       last->next=p;
       last=p;
    }
}
void Linkedlist::Display()
{
    Node*p=head;
do   
 {
        cout<<p->data<<"  ";
        p=p->next;
    }
    while(p!=NULL);
    cout<<endl;
}
int main()
{
    int A[]={11,22,33,44,55,66,77,88,99,110};
    Linkedlist l;
    l.create(A,10);
    l.Display();
    return 0;
}