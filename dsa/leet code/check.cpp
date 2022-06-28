#include<vector>
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        vector<int> count(nums.size()); 
        int factor=0;
        for(int i=0;i<nums.size();i++){
           
            while(nums[i]!=0){
               nums[i]= nums[i]/10;
                count[i]++;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(count[i]%2==0){
                factor++;
            }
        }
        return factor;
    }
};

int main(){
    Solution s;

    vector <int> nums={580,317,640,957,718,764};
    s.findNumbers(nums);
}