#include <vector>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int j = 0;
        int k = -1, check = 0;

        if(needle.size()>haystack.size() || (needle.size()==haystack.size() && needle!=haystack)){
            return -1;
        }
        for (int i = 0; i < haystack.size(); i++)
        {
            if (j >= needle.size())
            {
                break;
            }
            if (haystack[i] == needle[j])
            {
                j++;
                check++;
            }
            else
            {
                check = 0;
                j=0;
            }

            if (check == 1)
            {
                k = i;
            }
            
            if(check==0){
                k=-1;
            }

            
        }
        return k;
    }
};


int main(){
    Solution s;

    string s1= "mississippi";
    string g= "issip";

    s.strStr(s1,g);

}