#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       map<char,int> thismap;       

        int left=0,right=0,res=0;

        for(int i=0;i<s.length();i++)
        {
            if(thismap.find(s[i])!=thismap.end())
            {
                left=max(left,thismap[s[i]]);
                thismap[s[i]]=i+1;
            }
           

        res=max(res,right-left+1);
       thismap.insert(pair<char,int>(s[i],i+1));
       right++;
        }
        return res;
    }
};

int main(){
    Solution s;

    s.lengthOfLongestSubstring("abcabcbb");
}