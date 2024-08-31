#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
}*first=NULL,*second=NULL,*third=NULL;
void create(int A[],int n)
{
    int i;
    Node *t,*last;
    first=new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=new Node;
       t->data=A[i];
       t->next=NULL;
       last->next=t;
       last =t;
    }
}

void create2(int A[],int n)
{
    int i;
    Node *t,*last;
    second=new Node;
    second->data=A[0];
    second->next=NULL;
    last=second;
    for(i=1;i<n;i++)
    {
        t=new Node;
       t->data=A[i];
       t->next=NULL;
       last->next=t;
       last =t;
    }
}
void Display(Node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<"   ";
        p=p->next;
    }
    cout<<endl;
}
void Display1(Node *p)
{
          if(p!=NULL)
    {
        cout<<p->data<<"   ";
        Display1(p->next);
    }
}
int count(Node *p)
{
    int c=0;
    while(p!=NULL)
    {
       c++;
       p=p->next;
    }
    return c;
}
int add(Node *p)
{
    int c=0;
    while(p!=NULL)
    {
       c=c+p->data;
       p=p->next;
    }
    return c;
}
int max(Node *p)
{
    int c=INT32_MIN;
    while(p!=NULL)
    {
        if(p->data>c)
       c=p->data;
       p=p->next;
    }
    return c;
}
int min(Node *p)
{
    int c=INT32_MAX;
    while(p!=NULL)
    {
        if(p->data<c)
       c=p->data;
       p=p->next;
    }
    return c;
}
Node *search(Node *p,int key)
{
    while(p!=NULL)
    {
        if(key==p->data)
        return p;
        p=p->next;
    }
    return NULL;
}
Node *search1(Node *p,int key)
{
    Node *q=NULL;
    while(p!=NULL)
    {
        if(key==p->data)
        {
           q->next=p->next;
        p->next=first;
        first=p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}
void Insert(Node *p,int pos,int x)
{
    Node *t;
    if(pos==0)
    {
        t=new Node;
        t->data=x;
        t->next=first;
        first=t;
    }
    else if(pos>0)
    {
        for(int i=0;i<pos-1&&p;i++)
        {
        p=p->next;
        }
        if(p)
        {
            t=new Node;
            t->data=x;
            t->next=p->next;
            p->next=t;
        }
    }
}
void Insertinsort(Node *p,int x)
{
    Node *q,*t;
    q=NULL;
    while(p&&p->data<x)
    {
          q=p;
        p=p->next;
    }
    t=new Node;
    t->data=x;
    t->next=q->next;
    q->next=t;
}
int Delete(Node *p,int pos)
{
    int x;
    Node *q=NULL;
    p=first;
    if(pos==1)
    {
        first=first->next;
        x=p->data;
        return x;
    }
    else if(pos>1)
    {
        for(int i=0;i<pos-1&&p;i++)
        {
            q=p;
            p=p->next;
        }
        if(p)
        {
            q->next=p->next;
            x=p->data;
            return x;
        }
    }
    return 0;
}
void reverseallelement(Node *p,int n)
{
    p=first;
    int i=0;
    int A[n];
    while(p!=0)
    {
        A[i++]=p->data;
        p=p->next;
    }
    p=first;
    i--;
    while(p!=NULL)
    {
        p->data=A[i--];
        p=p->next;
    }
}
void reverselink(Node *p)
{
    Node *q,*r;
    q=NULL;
    r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first =q;
}
void concat(Node *p,Node *q)
{
    third=p;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=q;
    q=NULL;
}
void merge(Node *p,Node *q)
{
    Node *last=NULL;
    if(first->data<second->data)
    {
        third=last=first;
        first=first->next;
        last->next=NULL;
    }
    else
     {
        third=last=second;
        second=second->next;
        last->next=NULL;
    }
    while(p!=NULL&&second!=NULL)
    {
        if(first->data<second->data)
        {
            last->next=first;
            last=first;
            first=first->next;
            last->next=NULL;
        }
        else
         {
            last->next=second;
            last=second;
            second=second->next;
            last->next=NULL;
        }
    }
    if(first!=NULL)
    {
        last->next=first;
    }
    else
    {
        last->next=second;
    }
}
int isloop(Node *f)
{
    Node *p=NULL;
    Node *q=NULL;
    p=q=f;
    do
    {
        p=p->next;
        q=q->next;
        q=q?q->next:q;
        /* code */
    } while (p&&q&&p!=NULL);
    if(p==q)
    return 1;
    else 
    return 0;
    
}
int main()
{
    Node *t1,*t2;
    int A[]={11,22,33,44,55,66,77};
    create(A,7);
    t1=first->next->next;
    t2=first->next->next->next->next->next->next;
    t2->next=t1;
    cout<<isloop(first);
    
    return 0;
}