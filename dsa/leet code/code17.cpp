#include <bits/stdc++.h>

using namespace std;

class Solution {
    private:
    void BackTrack(int i,vector<string>& ans,string &digits,string &temp,unordered_map<char,string> mp){
     if(i>=digits.size())
     {
          ans.push_back(temp);
          return;
     }

     string str=mp[digits[i]];

     for(int j=0;j<str.size();j++)
     {
        temp.push_back(str[j]);
        BackTrack(i+1,ans,digits,temp,mp);
        temp.pop_back();
     }

    }
public:
    vector<string> letterCombinations(string digits) {

        if(digits.size()==0) return {};
       vector<string> ans;
       string temp= " ";
      
       unordered_map<char,string> mp;
       mp['2'] = "abc";
    mp['3'] = "def";
    mp['4'] = "ghi";
    mp['5'] = "jkl";
    mp['6'] = "mno";
    mp['7'] = "pqrs";
    mp['8'] = "tuv";
    mp['9'] = "wxyz";
     
     
       BackTrack(0,ans,digits,temp,mp);
     return ans;

    
       
    }
};