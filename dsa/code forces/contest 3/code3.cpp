#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> a(n),b(n);

        for(int i=0;i<n;i++){
        cin>>a[i];
        
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }


    for(int i=0;i<n;i++){
        if(i!=0 && b[i-1]>a[i]){
          
          cout<<b[i]-b[i-1]<<endl;

        }
        else{
            cout<<b[i]-a[i]<<endl;
        }
    }
    }
}