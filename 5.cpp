#include <bits/stdc++.h>
using namespace std;
int transfer(int *A, int n)
{
   for(int i=0;i,n;i++){
    int j=0;
    if(A[i]<0)
    {
        int z=A[i];
        A[i]=A[j];
        A[j]=z;
    }
    j++;
   }
}
int main()
{
    int n, i;
    cout << "Enter the size of Array:" << endl;
    cin >> n;
    int A[n];
    cout << " please Eenter the Array:" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cout << "this is your Array:" << endl;
    for (int p : A)
        cout << p << " ";
    cout << endl;
    transfer(A, n);
    for (int p : A)
        cout << p << " ";
    return 0;
}