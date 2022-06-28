#include <iostream>
#include<vector>
using namespace std;

int main() {
	int t;
    cin>>t;
while(t--){
        long long int n,k;
      cin>>n>>k;
       vector<long long int> circular(n);

       for(long long int i=0;i<n;i++){
           circular[i]=i+1;
           
       }
   long long int factor=0;
   
       while(factor<n){
          long long int index=(k-1)/(n-factor);
           for(long long int i=index;i<n-1-factor;i++){
               circular[i]=circular[i+1];
           }

        factor++;

        
       }

       if(circular[0]%2==0){
           cout<<"EVEN"<<endl;

       }
       else{
           cout<<"ODD"<<endl;
       }
}
	return 0;
}