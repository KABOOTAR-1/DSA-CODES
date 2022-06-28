#include <iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

int main(){

int t;
cin>>t;

while(t--){
    int n;
    cin>>n;
vector<int> tokens={1,1,2};
vector<int> even;
int count=0;
for(int i=0;i<n;i++){
    
    if(tokens[i]%2==0){
        even.push_back(tokens[i]);
        count++;
    }
    }
    if(count==0){
        cout<<count<<endl;
    }
    else{
        sort(even.begin(),even.end());

        int k=1;
       int val=0;
        if(even.size()==1){
            val=even[0];
            while(val%2==0){
                k++;
              val=val/2;
            }
        }
        else{
              val=(even[0]+even[even.size()-1]);
        while(val%2==0)
        {
            k++;
            val=val/2;    
        }
        }
        k=k+even.size()-2;
  cout<<k<<endl;
    }



}
    return 0;
    
}