#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

while(t--)
{
    int a,b;
    cin>>a>>b;

   string ans;

   for(int i=0;i<a+b-1;i++)
   {
    if(i%2==0)
    {
ans=ans+'1';
    }
    else{
        ans=ans+'0';
    }
   }
   cout<<ans<<endl;
}

    return 0;
}