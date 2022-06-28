#include <vector>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n%2!=0 || n==0){
            return false;
        }
        
        if(n==1){
            return true;
        }
        else{
            isPowerOfTwo(n/2);
        }
return true;
    }
};

int main(){

    Solution s;

    s.isPowerOfTwo(1);
}