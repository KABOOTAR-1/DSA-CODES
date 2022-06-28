#include <vector>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size()-1;

        if(digits[n]==9){
            while(digits[n]==9 && n>=0){
                digits[n]=0;
               n--;
              
            }
           if(n<0){
            digits.insert(digits.begin(),1);
           }
           else{
               digits[n]++;
           }
           
        }
        else{
            digits[n]++;
        }

        

         return digits;
        
    }
};

int main(){
    Solution s;

    vector<int> num={9};

    vector<int> ans=s.plusOne(num);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
}