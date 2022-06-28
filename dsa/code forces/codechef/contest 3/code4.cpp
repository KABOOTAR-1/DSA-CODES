#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
          int n,k;
          cin>>n>>k;

          int box;
          if(n%5==0){
            box=n/5;
          }
          else{
            box=(n/5)+1;
          }

          int val=(k-1)/5;

         int ans=box-val-1;

         if(ans<0){
            cout<<'0'<<endl;
         }
         else{
            cout<<ans<<endl;
         }
    }
    return 0;
}