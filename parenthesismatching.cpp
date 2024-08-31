#include<iostream>
using namespace std;
class Node
{
public:
char data;
Node *next;
};
class stack
{
private:
Node *st;
public:
stack(){st=new Node;
st =NULL;}
void push(char x);
char pop();
void Display();
char peek(int pos);
char stacktop();
int isempty();
int isfull();
int isbalance(char *exp);

};
int stack::isbalance(char *exp)
{
    int i;
   for(i=0;exp[i]!='\0';i++)
   {
    if(exp[i]=='(')
    push(exp[i]);
    else if(exp[i]==')')
    {
        if(isempty())return false;
    pop();
    }
   }
   if(isempty())
   return true;
   else 
   return false;

}
char stack::stacktop()
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
char stack::peek(int pos)
{
    Node *p=st;
    for(int i=0;p!=NULL&&i<pos-1;i++)
    p=p->next;
    if(p!=NULL)
    return p->data;
    else
    return (-1);
}
void stack::push(char x)
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
char  stack::pop()
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
    char *exp="((a+b)*(c-d))";
    stack st;
 cout<<  st.isbalance(exp);
       return 0;
}