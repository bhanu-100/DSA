#include<iostream>
using namespace std;
class Stack
{
public:
int size;
int top;
int *s;
};
void create(Stack *st)
{
  cout<<"enter the size of stack"<<endl;
     cin >>st->size;
     st->top=-1;
     st->s=new int[st->size];
}
void Display(Stack st)
{
    int i;
    for(i=st.top;i>=0;i--)
    cout<<st.s[i]<<"  ";
    cout<<endl;
}

void push(Stack *st,int x )
{
    if(st->top==st->size-1)
    cout<<"sack overflow"<<endl;
    else{
        st->top++;
        st->s[st->top]=x;
    }
}
int pop(Stack *st)
{
int x=-1;
if(st->top==-1)
cout<<"stack underflow"<<endl;
else{
    x=st->s[st->top];
    st->top--;
}
return x;
}


int main()
{
     Stack st;
     create(&st);
     push(&st,10);
     push(&st,12);
     push(&st,13);
     push(&st,14);
     Display(st);
    return 0;
}