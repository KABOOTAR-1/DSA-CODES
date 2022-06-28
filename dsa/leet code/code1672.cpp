#include<vector>
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
         int y=accounts[0].size(),x=accounts.size();
        int currenthigh;
         for(int i=0;i<x;i++){
             int sum=0;
             for(int j=0;j<y;j++){
              sum=sum+accounts[i][j];            
               }

               currenthigh=max(currenthigh,sum);
         }
         return currenthigh;
    }
};

int main(){
    Solution s;

    vector<vector<int>> accounts={{1,2,3},{3,2,1}};

    s.maximumWealth(accounts);




}