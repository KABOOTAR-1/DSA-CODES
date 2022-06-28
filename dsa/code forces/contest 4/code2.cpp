#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int> arr, int n)
{   
    
     if(n == 0 || n == 1)
        return n;       
    int j = 0;      
     unordered_map<int,int> mp;   
    for(int i=0; i<n; i++){
        if(mp.find(arr[i])==mp.end())
        {            
            arr[j++] = arr[i];       
        }
    }
    return j;
}

int main()
{
    int n=5,q=1;
    //cin>>n>>q;
    vector<int> p={5,3,1,5,2};

      /*for(int i=0;i<n;i++){
            int x;
            cin>>x;
            p.push_back(x);   
            
        }*/

sort(p.begin(),p.end());
    for(int i=0;i<q;i++){
        int x=3,y=2
        ;
        //cin>>x>>y;
     
        int sum=0;
        vector<int> x1;

        for(int i=n-1;i>n-1-x;i--){
            x1.push_back(p[i]);
        }

    
    sort(x1.begin(),x1.end());
    int j=1;
        while(y)
        {
            if(j<x1.size()){
            if(x1[j]!=x1[j-1]){
                sum=sum+x1[j-1];
                j++;
                y--;
                }
                }
                else{
                sum=sum+x1[x1.size()-1];
                }

        }

        cout<<sum<<endl;
 
 

    }

    return 0;
}