#include <vector>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        int count=0;
     vector<int> arr;
     for(int i=0;i<x;i++){
         int input;
         cin>>input;
         arr.push_back(input);
     }
 int even=0,odd=0;

for(int i=0;i<x;i++){
    if(arr[i]%2==0){
        even++;
    }
    else{
        odd++;
    }
}

if(even<odd){
    cout<< even<<endl;
}
else
cout<< odd<<endl;

   }
}