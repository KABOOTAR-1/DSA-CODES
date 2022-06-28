#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;
   //t=1;
    while(t--){
        int n;
        cin>>n;
        //n=1;

        vector<int> a(n),b(n);
        //vector<int> a={8};
        //vector<int> b={0};
    for(int i=0;i<n;i++){
        cin>>a[i];
        
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }

    if(n==1){
if(a[0]>=b[0]){
    cout<<"YES"<<endl;
}
else{
    cout<<"NO"<<endl;
}
    }
    
    else{
    int i=0;
    int diff=0;
    for(i=0;i<n;i++){
     diff=a[i]-b[i];
        if(b[i]!=0 && diff>=0){
            break;
        }
        else{
            if(diff<0){
               
                break;
            }else{
                diff=0;
            }
            
        }
        if(i==n-1){
     diff=INT_MAX;
        }
    }


if(diff>=0){
    int j=0;
    while(j<n){
       a[j]=a[j]-diff;
       if(a[j]<0){
           a[j]=0;
       }
       if(a[j]!=b[j]){
           j++;
           break;
       }
       j++;

    }
    if(a[--j]==b[j]){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
  

    }
      else{
        cout<<"NO"<<endl;
    }
    }
    

        

    }
}