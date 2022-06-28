#include <vector>
#include <bits/stdc++.h>
#include <iostream>
#include<stdio.h>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> check;
        for(int i=0;i<s.length(); i++){
            if(s[i] =='('||s[i] =='{' || s[i]== '['){
           check.push(s[i]);
            }
            else{
                if(!check.empty())
                {
                if(s[i]==')' && check.top() != '(') return false;
                if(s[i]=='}' && check.top() != '{') return false;
                if(s[i]==']' && check.top() != '[') return false;
                check.pop();
                }
                else{
                    return false;
                }
            }
        }
        return check.empty();
    }
};

int main(){
    Solution s;

    cout<<s.isValid("]");
}