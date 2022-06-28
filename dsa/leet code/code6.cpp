#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {

        int n = s.length();
        bool goingup = false;
        int currrow = 0;
        vector<string> rows(min(numRows, int(s.size())));

        if(numRows==1){
            return s;
        }

        for (int i = 0; i < n; i++)
        {
            char c = s[i];
            rows[currrow] += c;
            if (goingup)
            {
                --currrow;
            }
            else
            {
                ++currrow;
            }
            if (currrow == 0 || currrow == numRows - 1)
                goingup = !goingup;
        }
        string ret;
        for (int i = 0; i < rows.size(); i++)
        {
            ret += rows[i];
        }

        return ret;
    }
};

int main()
{
    Solution s;
    s.convert("PAYPALISHIRING", 3);
    return 0;
}