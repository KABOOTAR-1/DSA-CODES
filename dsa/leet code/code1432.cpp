#include<vector>
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    int numberOfSteps(int num) {
        int steps = 0;
        while(num != 0){
            if(num%2 == 0) num /= 2;
            else num--;
            steps++;
        }

        return steps;
    }
};

int main(){

}