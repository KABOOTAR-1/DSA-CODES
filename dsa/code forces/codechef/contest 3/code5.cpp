#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    //t=1;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        if (n == 1 && x == 1 )
        {


            cout << "a" << endl;
        }
        else
        {
            if ((n % 2 == 0 && x > n / 2) || (n % 2 != 0 && x > (n / 2) + 1) )
            {
                cout << "-1" << endl;
            }
            else
            {
                vector<char> ans(n);
                vector<char> alphabets(26);
                char aplhabet='a';
                for(int i=0;i<26;i++)
                {
                 alphabets[i]=aplhabet++;
                }
                if (n % 2 == 0)
                {
                   
                    for (int i = 0; i < n / 2; i++)
                    {
                         ans[n - i - 1] = alphabets[i%26];
                         ans[i] =alphabets[i%26];
                    }
                }
                else
                {
                    
                    int mid = n / 2;

                    for (int i = 0; i < n / 2; i++)
                    {
                        ans[i] = ans[n - i - 1] = alphabets[i%26];
                    }
                    ans[mid] = ++ans[mid-1] ;
                }
                for(int i=0;i<n;i++)
                {
                 cout<<ans[i];
                }
                cout<<endl;
            }
        }
    }
    return 0;
}