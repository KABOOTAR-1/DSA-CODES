#include <vector>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=0,k=nums.size(), count=0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(nums[i]);
            while(j<nums.size() && nums[i]==nums[j]){
                count++;
                j++;
            }
           
            i=j-1;

           k= k-count+1;
            count=0;
        }
for(int i=0;i<k;i++){
    nums[i]=ans[i];
}
        return k;
    }
};

int main(){
    Solution s;

    vector<int> nums={0,0,1,1,1,2,2,3,3,4};
    s.removeDuplicates(nums);
}