#include <iostream>
#include<vector>
using namespace std;

int main() {
	int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        if(n<=2){
            if(n==1){
                cout<<arr[0]<<endl;
            }
            else{
                cout<<arr[0]+arr[1]<<endl;
            }
        }
        else{
            int f=0,b=n-1,sum=-1000000,count=0;
            for(int i=0;i<n;i++){
                f=f%n;
                b=b%n;
               count=arr[f]+arr[b];
                sum=max(count,sum);
                f++;
                b++;
            }
            cout<<sum<<endl;
        }


    }
	return 0;
}