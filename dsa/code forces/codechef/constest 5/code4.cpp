#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t=1;
    //cin>>t;

    while(t--)
    {
        int n=12548,x=1;
       // cin>>n>>x;

        if(n==1||n==2){
            cout<<x*n<<endl;

        }else
        {
          long long int sum;
          int offset,extra;
         if(n>31)
         {
            offset=n/31;
         }
           sum=(long long int)pow(2,n-1)%1000000007;
              

          cout<<sum<<endl;
        }
    }
}