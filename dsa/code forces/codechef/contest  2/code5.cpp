#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        if(r-l<3){
            cout<<"-1"<<endl;
        }
        else{

      unordered_set<int> s;
       vector<int> arr(l-r);

       for(int i=0;i<r-l;i++){
           arr[i]=i+r;
       }
      for(int i=r;i<l;i++){
          s.insert(i);
      }

      int flag=0;

      for(int i=0;i<r-l;i++){
          for(int j=i+1;j<r-l;j--){
              for(int k=j+1;k<r-l;k++){
               int xr= arr[i]^arr[j]^arr[k];

               if(s.find(xr) != s.end() && xr != arr[i] && xr != arr[j] && xr != arr[k])
               {
                   flag++;
                   cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<" "<< xr<<endl;
                   break;
                   i=r-l;
                   j=r-1+1;
               }
               else{
                   cout<<"-1"<<endl;
               }

               

                                       }
          }
      }

        
    }
    }
	return 0;
}