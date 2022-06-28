#include<vector>
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size()/2;i++){
            for(int j=0;j<matrix[0].size()/2;j++){
                
                    int temp=matrix[i][j];
                    matrix[i][j]=matrix[j][i];
                    matrix[j][i]=temp;
                
            }
        }
        return matrix;
    }
};

int main(){
    Solution s;

    vector<vector<int>> matrix=
        {{1,2,3},{4,5,6},{7,8,9}};
        s.transpose(matrix);
    
}