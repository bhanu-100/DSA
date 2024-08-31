#include<bits/stdc++.h>
using namespace std;
int main(){
    int t=0;
    cin>>t;
    while(t>0){
   int n,k;
   cin>>n>>k;
   int array[n];
   for(int i=0;i<n;i++){
    cin>>array[i];
   }
int ans =0;
vector<int> vis(n,0);
for(int i=0;i<n;i++){
    if(array[i]==1){
        int start = (i-k<0)?0:i-k;
        int end = (i+k>n-1)?n-1:i+k;
        for(int j = start;j<=end;j++){
          if(array[j]==0 && vis[j]==0){
            ans++;
            vis[j] =1;
            break;
          }
        }
    }
}
cout<<ans<<endl;
t--;
    }
return 0;
}