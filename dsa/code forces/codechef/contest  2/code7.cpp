#include <iostream>
using namespace std;

long long gcd( int a,  int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
 
// Function to return LCM of two numbers
long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}
int main() {
	int t;
    cin>>t;
    //t=1;
    while(t--){
        int n;
        cin>>n;
        //n=23;

        int a=0,b=0;
if(n<2){
    if(n==0){
        cout<<"0"<<endl;
    }
    else{
        cout<<"-1"<<endl;
    }

}else{
        if(n%2==0){
        int mid=n/2;
        a=mid-1,b=mid+1;
        if(a%2==0){
       a=a-1;
          b=b+1;
        }
        cout<<(lcm(a,b)-gcd(a,b))<<endl;
        }
        else{
            int mid=(n-1)/2;
            a=a+mid;
            b=a+1;
            cout<<(lcm(a,b)-gcd(a,b))<<endl;
        }

        
    }
    }
	return 0;
}