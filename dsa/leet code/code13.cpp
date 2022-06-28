#include<vector>
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map <char,int> roman;
        roman.insert(pair<char,int>('I',1));
        roman.insert(pair<char,int>('V',5));
        roman.insert(pair<char,int>('X',10));
        roman.insert(pair<char,int>('L',50));
        roman.insert(pair<char,int>('C',100));
        roman.insert(pair<char,int>('D',500));
        roman.insert(pair<char,int>('M',1000));

   int result=roman[s[(s.length()-1)]];
        for(int i=s.length()-2;i>=0;i--){
         char x=s[i]; char y=s[i+1];
         if(roman[x]<roman[y]){
          
          result=result-roman[x];
          }
          else{
              result=result+roman[x];
          }

        }
        
        return result;

    }
};

int main(){
    Solution s;
string roman="III";
   int x= s.romanToInt(roman);
   cout<<x;

}