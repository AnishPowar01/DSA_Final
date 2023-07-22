#include<bits/stdc++.h>
using namespace std;

// 10 4
// 13

int solve(int number_candle, int req_candle)
{

    int ans = number_candle + (number_candle / req_candle) + ((number_candle / req_candle) + (number_candle % req_candle))/req_candle;


    return ans;

}
int main()
{
    int number_candle;
    int req_candle;

    cin>>number_candle;
    cin>>req_candle;

    cout<<solve(number_candle, req_candle)<<"";

    return 0;
}