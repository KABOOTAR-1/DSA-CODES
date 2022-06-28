#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        if(n%3==0){
            int ans=n/3;

            cout<<ans<<' '<<ans+1<<' '<<ans-1<<endl;
        }
        else{
            int ans=(n+(3-n%3))/3;
            int second=ans;
         int last=(ans-1-(3-n%3));
         if(last==0){
             last=1;
             second--;
         }
            cout<<second<<' '<<ans+1<<' '<<last<<endl;
        }
    
    }
}