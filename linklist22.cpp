#include<iostream>
using namespace std;
class node
{
    public :
    int data;
    node *next;
};
class link_list
{
    public:
    node *head,*tail;
link_list()
{
  head=NULL;
  tail=NULL;
}
void add(int n)
{
    node *tmp=new node;
    tmp->data=n;
    tmp->next=NULL;
    if(head==NULL)
    {
        head=tmp;
        tail=tmp;
    }
    else{
        tail->next=tmp;
        tail=tail->next;
    }
}
void display()
{
    node *n=head;
    while(n!=NULL)
    {
        cout <<tail->data<<" ";
        n=n->next;
    }
}
};
int main()
{
    link_list t;
    t.add(1);
    t.add(2);
    t.add(3);
    t.display();
    return 0;

}