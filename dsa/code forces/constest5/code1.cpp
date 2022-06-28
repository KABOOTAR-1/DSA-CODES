#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int a, b;
        cin >> a >> b;

        string ans;

        if (a <= b)
        {

            
                for (int i = 0; i < 2*a ; i++)
                {
                    if (i % 2 == 0)
                    {
                        ans += '1';
                    }
                    else
                    {
                        ans += '0';
                    }
                }

                for(int i=0;i<b-a;i++)
                {
                    ans+='1';
                }
            
        }
        else if (a > b)
        {
           
        for (int i = 0; i < 2*b; i++)
            {
                if (i % 2 == 0)
                {
                    ans += '0';
                }
                else
                {
                    ans += '1';
                }
            }

            for(int i=0;i<a-b;i++)
            {
                ans+='0';
            }
        
        }
        cout << ans << endl;
    }
    return 0;
}
