#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
      void backtrack(int n,vector<string> main,string& temp,int open,int close){
     if(temp.length()==2*n){
        main.push_back(temp);
        return;
     }

     if(open<n){
        temp.push_back('(');
        backtrack(n,main,temp,open+1,close);
    temp.pop_back();

     }
     if(close<open){
        temp.push_back(')');
        backtrack(n,main,temp,open,close+1);
        temp.pop_back();
     }
      }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="";
        backtrack(n,ans,s,0,0);
        return ans;
    }
};