#include <vector>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length()-1;
int i=0;
int check=1;
int count=0;

        for( i=n;i>=0;i--){
           
          if(s[i] ==' ' && check==0){
            break;
          }

          if(s[i]!=' '){
              check=0;
          }
          else{
              count++;
          }
        
        
        }
        return n-i;

    }
};

int main(){
    Solution s;

    string str="   fly me   to   the moon  ";

    s.lengthOfLastWord(str);
}