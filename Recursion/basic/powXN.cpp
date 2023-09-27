#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double power(double x, long n)
    {
        if (n == 0)
        {
            return 1;
        }

        if (n < 0)
        {
            return power(1 / x, -n);
        }

        if (n & 1)
        {
            return x * power(x * x, n / 2);
        }

        return power(x * x, n / 2);
    }
};

int main()
{
    Solution obj;
    double x = 2.10000;
    int n = 3;
    cout << obj.power(x, (long)n) << endl;

    return 0;
}