#include <vector>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
         while (l <= r) {
        int m = l + (r - l) / 2;
 
        // Check if target is present at mid
        if (nums[m] == target)
            return m;
 
        // If target greater, ignore left half
        if (nums[m] < target)
            l = m + 1;
 
        // If target is smaller, ignore right half
        else
            r = m - 1;
    }


   int k=0;
   for(int i=0;i<=nums.size();i++){
      
       if(k>=nums.size()|| nums[i]>target){
           
           break;
       }
        k++;
      
   }
   return k;
    }
};

int main(){
    Solution s;

    vector<int> ques={1,3,5,6};
    cout<<s.searchInsert(ques,7);
}