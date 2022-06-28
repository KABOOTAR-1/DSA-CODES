#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    cin>>t;
    
    while(t--){
        int n,m;
        vector<int> a;

        cin>>n>>m;
int sum=0;

        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a.push_back(x);   
            
        }

        for(int i=0;i<n;i++){
            sum=sum+a[i];
        }
if(m>=sum){
    cout<<"0"<<endl;
}
else{
    cout<<(sum-m)<<endl;
}


    }
    return 0;

}