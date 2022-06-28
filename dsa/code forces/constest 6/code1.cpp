#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--){
       long long int n,m;
        cin>>n>>m;

        long long int sum=0;

        sum+=(((m+1)*(m))/2)-m;

        sum+=m*(((n)*(n+1))/2);
        
        cout<<sum<<endl;
    }


 return 0;
}