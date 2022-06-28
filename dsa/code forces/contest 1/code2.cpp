#include<vector>
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int no_stu;
        cin>>no_stu;
        vector<int> shoe_size;
        for(int i=0;i<no_stu;i++){
            cin >>shoe_size[i];
        }

        for(int i=0;i<no_stu;i++){
            if(shoe_size[i]>no_stu){
                cout<< "-1"<<endl;
            }
        }
        
        for(int i=0;i<no_stu;i++){

        }

        unordered_map<int,int> map_check;
        
     for(int i=0;i<no_stu;i++){
        if(map_check.find(shoe_size[i])!=map_check.end()){
            map_check[shoe_size[i]]++;
          
            
        }
        else{
            map_check[shoe_size[i]]=1;
          
        }
        
        }

        for(int i=0;i<no_stu;i++){
            if(map_check[shoe_size[i]]==1)
            cout<< "-1"<<endl;

        else{
            
            
                int k=0;
                for(int j=i+1;j<no_stu;j++){
                    if(shoe_size[i]==shoe_size[j] && k==0 ){
                        swap(shoe_size[i],shoe_size[j]);
                        k=1;
                    }
                }
            for(int i=0;i<no_stu;i++){
                
            }
        }

        }


        
    }
}