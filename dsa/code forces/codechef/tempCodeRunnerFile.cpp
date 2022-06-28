#include <iostream>
#include<vector>
using namespace std;

int main() {
	int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;
       vector<int> circular(n);

       for(int i=0;i<n;i++){
           circular[i]=i+1;
       }
       int factor; 
       int index;
       for(int i=0;i<=n;i++){
          index=(i+k-1)/n;
          if(i==(n-1)){
              break;
          }
               if(circular[index]%2==0){
                   cout<<"EVEN"<<endl;
               }
               else{
                   cout<<"ODD"<<endl;
               }

       }

    }
	return 0;
}