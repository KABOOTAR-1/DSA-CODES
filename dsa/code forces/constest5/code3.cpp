#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
     while(t--)
     {
         int n;
         cin>>n;

         vector<int> a;
         int sum=0;
         for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a.push_back(x);
            sum+=x;
         }

         /*for(int i=0;i<n;i++){
            sum+=a[i];
         }*/
     if(sum!=0 || a[0]<=0){
        cout<<"NO"<<endl;
     }
     else
     {
        bool isZero=true;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=0){
           isZero=false;
            }
        }

    if(isZero==true){
        cout<<"YES"<<endl;
    }
    else{
        int i;
        for(int i=n-1;i>=0;i--)
        {
           if( a[i]!=0)
           {
            if(a[i]<0){
                cout<<"YES"<<endl;
                break;
            }
            else{
                cout<<"NO"<<endl;
                break;
            }
           }

        }
    }


     }
     }

     return 0;
}