#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
     int count=0;
        cin>>n;
        cin>>s;

if(s ==" "){
    cout<<'0'<<endl;
}else{
    if(n%2!=0)
    {
        count=1;
    }
        int mid=n/2;

        for(int i=0;i<mid;i++)
        {
            if(s[i] == ')')
            {
                count+=2;
            }
        }

   cout<<count<<endl;
    }
    }
}