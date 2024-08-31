// #include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Array
{
    public:
    int A[10];
    int size;
    int length;
};
void Display(Array ar)
{
    for(int i=0;i<ar.length;i++)
    cout<<ar.A[i]<<"  ";
}

int main()
{
    Array ar={{8,3,9,15,6,10,7,2,12,4},20,10};
    Display(ar);
    return 0;
}