#include <iostream>
using namespace std;

int main() {
	int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;

        if(n<(3*x)){
        cout<<"0"<<endl;
        }
        else{

        cout<<n/(x*3)<<endl;
        }

       
    }
	return 0;
}