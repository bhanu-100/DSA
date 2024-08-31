#include<bits/stdc++.h>
using namespace std;
int main(){
 const int n = 10;
  int a[n];
  std::cout << "Enter 10 elements: ";
  for (int i = 0; i < n; i++)
  {
    std::cin >> a[i];
  }
  int* max=a; //larger element pointer initially pointed to first element
  max=std::max_element(a, a + n);
  int index = max - a;
  std::cout << "Index of largest element is: " << index << "\n";
return 0;
}