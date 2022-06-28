#include<vector>
#include <bits/stdc++.h>
using namespace std;

int main(){

int t;
cin>>t;

while(t--){
    int n;
    cin>>n;
vector<int> tokens(n);
vector<int> even;
int count=0;
  for(int i=0;i<n;i++)
  {
    cin>>tokens[i];
    if(tokens[i]%2==0)
    {
        even.push_back(tokens[i]);
       
    }
  }

  if(even.size()==0){
      cout<<"0"<<endl;
  }
  else{
      int k;
      if(even.size()==1){
          if(even.size()==tokens.size()){
              int k=even[0];
            while(k%2==0){
                k=k/2;
            }
            cout<<k<<endl;
          }
          else{
              cout<<even.size()<<endl;
          }
      }
      else{
          if(even.size()<tokens.size()){
              cout<<even.size()<<endl;
          }
          else{
               sort(even.begin(),even.end());
               int val=0;
               k=2;
               for(int i=0;i<even.size();i++){
            val=val+even[i];
               }
               while(val%2==0)
               {
                 k++;
                 val=val/2;
                }
                cout<<k<<endl;
          }
      }
  }
}
    return 0;
    
}