#include<iostream>
using namespace std;
#include<math.h>
class Node
{
    public:
   int coeff;
   int exp;
   Node *next;
};
class polynomial
{
   private:
Node *poly=NULL;
public:
polynomial()
{
poly=new Node;
}
void create() 
{
    Node *last=NULL;
    Node *t=NULL;
  int i, n;
cout <<"Enter the no.of term in polynomial"<<endl;
cin>>n;
cout<<"Enter coeffiecent and degree of term of poly"<<endl;
for(i=0;i<n;i++)
{
    t=new Node;
  cin>>t->coeff>>t->exp;
  t->next=NULL;
  if(i==0)
  {
    poly=last=t;
  }
  else{
    last->next=t;
    last=t;
  }
}
}
void Display()
{
   Node * p=NULL;
    p=poly;
    while(p!=NULL)
    {
        cout<<p->coeff<<"x^"<<p->exp<<"+";
        p=p->next;
    }
    cout<<endl;
}
long eval(int x)
{
    Node *p=NULL;
    long val=0;
    while(p!=NULL)
    {
    val=val+p->coeff*pow(x,p->exp);
    p=p->next;
    }
    return val;
}
};
int main()
{
    int x;
    polynomial pt;
    pt.create() ;
    pt.Display();
    cout<<"enter the val of x"<<endl;
    cin>>x;
    cout<<pt.eval(x)<<endl;
    return 0;
}