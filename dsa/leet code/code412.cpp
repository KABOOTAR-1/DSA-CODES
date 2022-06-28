#include<vector>
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> s(n);

    for(int i=0;i<n;i++){
        if((i+1)%3==0){
           s[i]=s[i]+"Fizz"; 
        }
        
        if((i+1)%5==0){
            s[i]=s[i]+"Buzz";
        }
        
        if(s[i]==""){
            s[i]=to_string(i+1);
        }

        
    }    
    return s;

    }
};