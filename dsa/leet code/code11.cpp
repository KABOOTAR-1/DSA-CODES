#include<vector>
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size()-1,i=0;
        int m=0,tall=0;
        while(n!=i)
        {
          int x=n-i;
         if(height[i]>height[n])
         {
           tall=height[n];
           n--; 
           
         }
         else{
            tall=height[i];
            i++;
         }
         m=max(m,x*tall);
    
        }
    }
};