#include<vector>
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {

        if(x<0 || (x%10==0 && x!=0)){
            return false;
        }


        int reveresed=0;

        while(x>reveresed){
            reveresed=reveresed*10 + x%10;
            x=x/10;

        }

        return x==reveresed || x==reveresed/10;

    }
      
    
};

int main(){
    Solution s;

    bool check=s.isPalindrome(121);

cout<<check;
}