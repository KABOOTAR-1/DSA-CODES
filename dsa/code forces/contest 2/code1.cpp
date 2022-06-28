#include <iostream>

using namespace std;

int main()
{

    int t;

    cin >> t;

    while (t--)
    {
        int x;
        cin >> x;
        int y = 0;
        while ((x & y) <= 0 || (x ^ y) <= 0)
        {
            if ((x & y) > 0 && (x ^ y) > 0)
            {
            }
            else
            {
                y++;
            }
        }
        cout << y << endl;
    }

    return 0;
}