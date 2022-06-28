#include <iostream>
using namespace std;

int main() {
int t;
cin>>t;

while(t--){
    int x,y;
 cin>>x>>y;
 int l=0,k=0;
 while(x!=y){
    if(x<y){
        x=x+1;
        l++;
    }
    else{
        y=y+2;
        k++;
    }
    cout<<(l+k)<<endl;
     
 }
}
	return 0;
}
