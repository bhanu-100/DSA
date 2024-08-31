#include<iostream>
using namespace std;
template <class T>
class Array
{ 
    public:
     T *A;
     int size;
     int length;
     
     Array()
     {
      size=20;
      A=new T[size];
      length=0;
      
     }
     Array(int s,int P[])
     {
      size=s;
      length=10;
      A=new T[size];
      for(int j=0;j<length;j++)
      {
        A[j]=P[j];
      }
     
    }
     void Display();
     void Append();
     void swap(T *x,T *y);
     void insert(int index,T x);
     T  Delete(int index );
     int linearsearch(T key);
     int binarysearch(T key);
     T Get(int index);
     void set(int index,T x);
     T max();
     T min();
     T sum();
     float Average();
     void reverse();
     void Insertsort(T x);
     int  Issorted();
     void Rearrange();

      ~Array()
      {
        delete []A;
      }
};
template<class T>
void Array<T> :: Display()
{
    for(int i=0;i<length;i++)
    cout<<A[i]<<"  ";
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
}
template <class T>
void Array<T>::Append()
{
  T x;
  cout<<"Enter the value"<<endl;
  cin>>x;
    A[length++]=x;
}
template <class T>
void Array<T>::swap(T *x,T *y)
{
    T t;
    t=*x;
    *x=*y;
    *y=t;
}
template <class T>
void Array<T>::insert(int index,T x)
{
    if(index>=0 && index<length)
    {
        for(int i=length;i>index;i--)
       {
          A[i]=A[i-1];
       }
       A[index]=x;
       length++;
    }

}
template <class T>
T Array<T>::Delete(int index )
{
    if (index>=0&&index<length)
    {
        int x =A[index];
        for(int i=index;i<length;i++)
        A[i]=A[i+1];
        length--;
        return x;
    }
}
template <class T>
int Array<T>::linearsearch(T key)
{
    for(int i=0;i<length;i++)
   {
     if(key==A[i])
    return i;
   }
    return -1;
}
template<class T>
int Array<T>::binarysearch(T key)
{
     int l=0;
    int h=length-1;
     while(l<=h)
 {
    int mid=(l+h)/2;
    if(key==A[mid])
    return mid;
    else if(key>A[mid])
    {
        l=mid+1;
    }
    else 
    {
        h=mid-1;
    }
  }
  return -1;
}
template<class T>
T Array<T>::Get(int index)
{
    if(index>=0&&index<length)
    {
        return A[index];
    }
}
template<class T>
void Array<T>::set(int index,T x)
{
    if(index>=0&&index<length)
    {
     A[index]=x;
    }
}
template<class T>
T Array<T>::max()
{
    int max=A[0];
    for(int i=1;i<length;i++)
    {
        if(max<A[i])
        max=A[i];
    }
   return max;
}
template <class T>
T Array<T>::min()
{
    int min=A[0];
    for(int i=1;i<length;i++)
    {
        if(min>A[i])
        min=A[i];
    }
   return min;
}
template<class T>
T Array<T>::sum()
{
    T s=0;
  for(int i=0;i<length;i++)
    {
        s+=A[i];
    }
    return s;
}
template<class T>
float Array<T>:: Average()
{
     float avg=sum()/length;
     return avg;
}
template <class T>
void Array<T>::reverse()
{
for(int i=0,j=length-1;i<j;i++,j--)
{
    T temp= A[i];
    A[i]=A[j];
    A[j]=temp;
}   
}
template<class T>
void Array<T>::Insertsort(T x)
{
    int i=length-1;
    while(A[i]>x)
    {
        A[i+1]=A[i];
        i--;
    }
    A[i+1]=x;
    length++;
}
template <class T>
int Array<T>::Issorted()
{
   for(int i=0;i<length-1;i++)
   {
    if(A[i]>A[i+1])
    return 0;
   }
   return 1;
}
template<class T>
void Array<T>:: Rearrange()
{
    int i,j;
    i=0;
    j=length-1;
    while(i<j)
    {
    while(A[i]<0)
    {
        i++;
    }
    while(A[j]>0)
    {
        j--;
    }
    swap(&A[i],&A[j]); 
    }
}
template<class T>
Array<T> *merg(Array<T> *ar1,Array<T> *ar2)
{
    int i,j,k;
    i=j=k=0;
  Array<T> *ar3;
  ar3= new Array<T>[sizeof(Array<T>)];
  while(i<ar1->length && j<ar2->length)
  {
    if(ar1->A[i]<ar2->A[j])
    ar3->A[k++]=ar1->A[i++];
    else 
     ar3->A[k++]=ar2->A[j++];
  }
  for(;i<ar1->length;i++)
  {
    ar3->A[k++]=ar1->A[i];
  }
   for(;j<ar2->length;j++)
  {
    ar3->A[k++]=ar2->A[j];
  }
   ar3->length=ar1->length+ar2->length;
   ar3->size=20;
   return ar3;
}
template<class T>
Array<T> *Union(Array<T> *ar1,Array<T> *ar2)
{
    int i,j,k;
    i=j=k=0;
  Array<T> *ar3;
  ar3= new Array<T>[sizeof(Array<T>)];
  while(i<ar1->length && j<ar2->length)
  {
    if(ar1->A[i]<ar2->A[j])
    ar3->A[k++]=ar1->A[i++];
    else if(ar1->A[i]>ar2->A[j])
     ar3->A[k++]=ar2->A[j++];
     else
    {
         ar3->A[k++]=ar2->A[j++];
         i++;
    }
  }
  for(;i<ar1->length;i++)
  {
    ar3->A[k++]=ar1->A[i];
  }
   for(;j<ar2->length;j++)
  {
    ar3->A[k++]=ar2->A[j];
  }
   ar3->length=ar1->length+ar2->length;
   ar3->size=20;
   return ar3;
}
template<class T>
Array<T> *Intersection(Array<T> *ar1,Array<T> *ar2)
{
    int i,j,k;
    i=j=k=0;
  Array<T> *ar3;
  ar3= new Array<T>[sizeof(Array<T>)];
  while(i<ar1->length && j<ar2->length)
  {
    if(ar1->A[i]<ar2->A[j])
    i++;
    else if(ar1->A[i]>ar2->A[j])
     j++;
     else if(ar1->A[i]==ar2->A[j])
    {
         ar3->A[k++]=ar2->A[j++];
         i++;
    }
  }
   ar3->length=k;
   ar3->size=20;
   return ar3;
}
template <class T>
Array<T> *Difference(Array<T> *ar1,Array<T> *ar2)
{
    int i,j,k;
    i=j=k=0;
  Array<T> *ar3;
  ar3= new Array<T>[sizeof(Array<T>)];
  while(i<ar1->length && j<ar2->length)
  {
    if(ar1->A[i]<ar2->A[j])
     ar3->A[k++]=ar1->A[i++];
    else if(ar1->A[i]>ar2->A[j])
     j++;
     else 
     {
        i++;
        j++;
    }
  }
  for(;i<ar1->length;i++)
  {
    ar3->A[k++]=ar1->A[i];
  }
   ar3->length=k;
   ar3->size=20;
   return ar3;
}

/*****************************/
int main()
{
 
  int n;
  cout<<"*****************Welcome to Array program********************"<<endl;
  do
  {
  cout<<"please Enter your choice"<<endl;
  cout<<"1.Display"<<endl;
  cout<<"2.Append"<<endl;
  cout<<"3.swap"<<endl;
  cout<<"4.Insert"<<endl;
  cout<<"5.Delete"<<endl;
  cout<<"6.linearsearch"<<endl;
  cout<<"7.Binarysearch"<<endl;
  cout<<"8.Get"<<endl;
  cout<<"9.set"<<endl;
  cout<<"10.max"<<endl;
  cout<<"11.min"<<endl;
  cout<<"12.sum"<<endl;
  cout<<"13.average"<<endl;
  cout<<"14.reverse"<<endl;
  cout<<"15.insertsort"<<endl;
  cout<<"16.issorted"<<endl;
  cout<<"17.Rearrange"<<endl;
  cout<<"18.merge two array"<<endl;
  cout<<"19.union of two array"<<endl;
  cout<<"20.intersection of two array"<<endl;
  cout<<"21.difference of two array"<<endl;
  cout<<"22.Exit"<<endl;
  cin>>n;
  switch (n)
  {
  case 1:
    {
       int X;
       cout<<"Enter the size of an array"<<endl;
        cin>>X;
       int P[]={10,20,30,40,50,60,70,80,90,100};
       Array<int> ar(X,P);
       ar.Display();
      
    }
    break;
     case 2:
    {
      
       int X;
     cout<<"Enter the size of an array"<<endl;
     cin>>X;
       int P[]={10,20,30,40,50,60,70,80,90,100};
      Array<int> ar(X,P);
     ar.Append();
     ar.Display();
    }
    break; 
    case 3:
    {
       int X;
  cout<<"Enter the size of an array"<<endl;
  cin>>X;
 int P[]={10,20,30,40,50,60,70,80,90,100};
  Array<int> ar(X,P);
      int a,b;
      cout<<"Enter two index"<<endl;
      cin>>a>>b;
    ar.swap(&ar.A[a],&ar.A[b]);
    ar.Display();
    }
    break; 
    case 4:
    {
       int X;
  cout<<"Enter the size of an array"<<endl;
  cin>>X;
 int P[]={10,20,30,40,50,60,70,80,90,100};
  Array<int> ar(X,P);
      ar.insert(4,550);
     ar.Display();
    }
    break; 
    case 5:
    {
       int X;
  cout<<"Enter the size of an array"<<endl;
  cin>>X;
 int P[]={10,20,30,40,50,60,70,80,90,100};
  Array<int> ar(X,P);
     ar.Delete(4);
     ar.Display();
    }
    break;
     case 6:
    {
       int X;
  cout<<"Enter the size of an array"<<endl;
  cin>>X;
 int P[]={10,20,30,40,50,60,70,80,90,100};
  Array<int> ar(X,P);
      cout<<ar.linearsearch(5)<<endl;
    }
    break; 
    case 7:
    {
       int X;
  cout<<"Enter the size of an array"<<endl;
  cin>>X;
 int P[]={10,20,30,40,50,60,70,80,90,100};
  Array<int> ar(X,P);
     cout<<ar.binarysearch(60)<<endl;
    }
    break; 
    case 8:
    {
       int X;
  cout<<"Enter the size of an array"<<endl;
  cin>>X;
 int P[]={10,20,30,40,50,60,70,80,90,100};
  Array<int> ar(X,P);
      cout<<ar.Get(6)<<endl;
    }
    break; 
    case 9:
    {
       int X;
  cout<<"Enter the size of an array"<<endl;
  cin>>X;
 int P[]={10,20,30,40,50,60,70,80,90,100};
  Array<int> ar(X,P);
      ar.set(8,11);
     ar.Display();
    }
    break;
     case 10:
    {
       int X;
  cout<<"Enter the size of an array"<<endl;
  cin>>X;
 int P[]={10,20,30,40,50,60,70,80,90,100};
  Array<int> ar(X,P);
     cout<<ar.max()<<endl;
    } 
    break;
    case 11:
    {
       int X;
  cout<<"Enter the size of an array"<<endl;
  cin>>X;
 int P[]={10,20,30,40,50,60,70,80,90,100};
  Array<int> ar(X,P);
     cout<<ar.min()<<endl;
     
    }
    break; 
    case 12:
    {
       int X;
  cout<<"Enter the size of an array"<<endl;
  cin>>X;
 int P[]={10,20,30,40,50,60,70,80,90,100};
  Array<int> ar(X,P);
   cout<< ar.sum()<<endl;
   
    }
    break;
     case 13:
    {
       int X;
  cout<<"Enter the size of an array"<<endl;
  cin>>X;
 int P[]={10,20,30,40,50,60,70,80,90,100};
  Array<int> ar(X,P);
    cout<<ar.Average()<<endl;
     
    }
    break; 
    case 14:
    {
       int X;
  cout<<"Enter the size of an array"<<endl;
  cin>>X;
 int P[]={10,20,30,40,50,60,70,80,90,100};
  Array<int> ar(X,P);
        ar.reverse();
     ar.Display();
    }
    break; 
    case 15:
    {
       int X;
  cout<<"Enter the size of an array"<<endl;
  cin>>X;
 int P[]={10,20,30,40,50,60,70,80,90,100};
  Array<int> ar(X,P);
     ar.Insertsort(15);
     ar.Display();
    }
    break; 
    case 16:
    {
       int X;
  cout<<"Enter the size of an array"<<endl;
  cin>>X;
 int P[]={10,20,30,40,50,60,70,80,90,100};
  Array<int> ar(X,P);
      int t;
    t= ar.Issorted();
    if (t==1)
    cout<<"sorted"<<endl;
    else
    cout<<"not sorted"<<endl;
    }
    break; 
    case 17:
    {
 int X;
  cout<<"Enter the size of an array"<<endl;
  cin>>X;
 int P[]={10,20,30,40,50,60,70,80,90,100};
  Array<int> ar(X,P);
     ar.Rearrange();
     ar.Display();
    }
    break; 
    case 18:
    {
       int X,Y;
  cout<<"Enter the size of an array"<<endl;
  cin>>X>>Y;
 int P[]={10,20,30,40,50,60,70,80,90,100};
  Array<int> ar(X,P);
       int Q[]={11,22,33,44,55,66,77,88,99,110};
       Array<int> ar1(Y,Q);
      Array<int> *ar3; 
      ar3= merg(&ar,&ar1);
     ar3->Display();
    }
    break; 
    case 19:
    {
       int X,Y;
  cout<<"Enter the size of an array"<<endl;
  cin>>X>>Y;
 int P[]={10,20,30,40,50,60,70,80,90,100};
  Array<int> ar(X,P);
       int Q[]={11,22,33,44,55,66,77,88,99,110};
       Array<int> ar1(Y,Q);
       Array<int> *ar3; 
       Union(&ar,&ar1);
        ar3->Display();
    }
    break; 
    case 20:
    {
       int X,Y;
  cout<<"Enter the size of an array"<<endl;
  cin>>X>>Y;
 int P[]={10,20,30,40,50,60,70,80,90,100};
  Array<int> ar(X,P);
       int Q[]={11,22,33,44,55,66,77,88,99,110};
       Array<int> ar1(Y,Q);
     Array<int> *ar3; 
     Intersection(&ar,&ar1);
     ar3->Display();
    }
    break;
    case 21:
    {
       int X,Y;
  cout<<"Enter the size of an array"<<endl;
  cin>>X>>Y;
 int P[]={10,20,30,40,50,60,70,80,90,100};
  Array<int> ar(X,P);
       int Q[]={11,22,33,44,55,66,77,88,99,110};
       Array<int> ar1(Y,Q);
       Array<int> *ar3; 
      Difference(&ar,&ar1);
      ar3->Display();
    }
    break;
     case 22:
    {
      return 0;
    }
    break;
  default:
  {
    cout<<"wrong choice"<<endl;
    break;
  }
    
  }
  } while (n>0&&n<=21);
  
cout<<"Thankyou"<<endl;
  return 0;
}
