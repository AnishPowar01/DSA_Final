// quotient * divior + remainder = dividend; 
#include<bits/stdc++.h>
using namespace std;
int main()
{
    double num = 29;
    double divi = 7;

    int start = 0;
    int end = num;

    int ans = 0;

    while(start <= end)
    {
        double mid = (start + end)/2;

        if(mid * divi <= num)
        {
            ans = mid;

            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    cout<<ans<<" "<<endl;
    return 0;
}