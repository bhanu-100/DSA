#include<iostream>
using namespace std;
class Node
{
public:
int data;
Node *next;
};
class stack
{
private:
Node *st;
public:
stack(){st=new Node;
st =NULL;}
void push(int x);
int pop();
void Display();
int peek(int pos);
int stacktop();
int isempty();
int isfull();
};
int stack::stacktop()
{
    if(st)
    return st->data;
}
int stack::isempty()
{
    return st?0:1;

}
int stack::isfull()
{
    Node *t=new Node;
    int r=t?1:0;
}
int stack::peek(int pos)
{
    Node *p=st;
    for(int i=0;p!=NULL&&i<pos-1;i++)
    p=p->next;
    if(p!=NULL)
    return p->data;
    else
    return -1;
}
void stack::push(int x)
{
     Node *t=new Node;
    if(t==NULL)
    cout<<"stack over flow"<<endl;
    else{
        t->data=x;
        t->next=st;
        st=t;
    }
}
int  stack::pop()
{
    Node *t=NULL;
    int x=-1;
    if(st==NULL)
    cout<<"stack under flow"<<endl;
    else{
        t=st;
         x=st->data;
         st=st->next;
         delete t;
    }
    return x;
}
void stack::Display()
{
    Node *p=st;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main()
{
    stack st;
   
       return 0;
}