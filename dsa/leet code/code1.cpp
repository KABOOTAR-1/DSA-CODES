#include<vector>
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int, int> hashmap;
        vector<int> out;
        for(int i=0;i<nums.size();i++)
        {
            int secondele=target-nums[i];
            if(hashmap.find(secondele)!=hashmap.end()&&hashmap.find(secondele)->second!=i)
            {
                out.push_back(i);
                out.push_back(hashmap.find(secondele)->second);
                return out;
            }
            hashmap.insert(pair<int,int>(nums[i],i));
        }
    }
};