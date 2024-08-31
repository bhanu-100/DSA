#include<bits/stdc++.h>
using namespace std;
int max(int *A,int n)
{
    int x=A[0];
    for(int i=0;i<n;i++)
    {
    if(A[i]>x)
    {
      x=A[i];
    }
    }
    return x;
}
int min(int *A,int n)
{
    int x=A[0];
    for(int i=0;i<n;i++)
    {
    if(A[i]<x)
    {
      x=A[i];
    }
    }
    return x;
}
int main(){
int n,i;
    cout<<"Enter the size of Array:"<<endl;
    cin>>n;
    int A[n];
    cout<<" please Eenter the Array:"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>A[i];
    }
    cout<<"this is your Array:"<<endl;
for(int p:A)
cout<<p<<" ";
cout<<endl;
cout<<"max of Araay is:"<<max(A,n)<<endl;
cout<<"min of Araay is:"<<min(A,n)<<endl;
return 0;
}