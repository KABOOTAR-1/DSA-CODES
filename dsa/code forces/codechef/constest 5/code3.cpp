#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int x1,y1,x2,y2;

        cin>>x1>>y1;
        cin>>x2>>y2;

        if(((abs(x1-x2)==2 ||abs(x1-x2)==4) && y1-y2==0)||((abs(y1-y2)==2||abs(y1-y2)==4 ) && x1-x2==0))
        {
            cout<<"YES"<<endl;
        }
        else if(abs(x1-x2)==1&& abs(y1-y2)==1){
            if((x1==8|| x1==1) && (y1==1 || y1==8) ||(x2==8|| x2==1) && (y2==1 || y2==8))
            {
                cout<<"NO"<<endl;
            }
            else
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    
    return 0;
}