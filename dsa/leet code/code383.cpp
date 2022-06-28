#include<vector>
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        unordered_map <char,int> count;

  
        for(int i=0;i<magazine.length();i++){
            if(count.find(magazine[i])!=count.end()){
                count[magazine[i]]++;
            }
            else{
                count.insert(pair<char,int>(magazine[i],1));
            }
        }

        for(int i=0;i<ransomNote.length();i++){
            if(count.find(ransomNote[i])==count.end()){
                return false;
            }
             
             count[ransomNote[i]]--;
             if(count[ransomNote[i]]<0){
                 return false;
             }

        }

        return true;

        
        
    }
};

int main(){

    Solution s;

    s.canConstruct("bg" ,"efjbdfbdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj");
}