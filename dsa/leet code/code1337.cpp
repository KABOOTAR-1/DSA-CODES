#include<vector>
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> v;
        for(int i=0; i<mat.size(); i++) {
            int lo=0, hi=mat[i].size()-1, mid, cnt=0;
            while(lo<=hi) {
                mid=lo+((hi-lo)>>1);
                if(mat[i][mid]) cnt+=mid-lo+1, lo=mid+1;
                else hi=mid-1;
            }
            v.push_back({cnt, i});
        }
        sort(v.begin(), v.end());
        vector<int> ret;
        for(int i=0; i<k; i++)
            ret.push_back(v[i].second);
        return ret;
    }
};