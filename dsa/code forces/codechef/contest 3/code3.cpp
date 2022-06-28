#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        string s, ans;
        cin >> s;

        for (int i = 0; i < n; i = i + 2)
        {
            if (s[i] == '0')
            {
                if (s[i + 1] == '0')
                {
                    ans = ans + 'A';
                }
                else
                {
                    ans = ans + 'T';
                }
            }
            else
            {
                if (s[i + 1] == '0')
                {
                    ans = ans + 'C';
                }
                else
                {
                    ans = ans + 'G';
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}
