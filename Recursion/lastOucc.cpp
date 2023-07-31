#include <bits/stdc++.h>
using namespace std;
void solve(int index, string &str, int &ans, char ch)
{

    if (index >= str.length())
    {
        return;
    }

    if (str[index] == ch)
    {
        ans = index;
    }

    solve(index + 1, str, ans, ch);
}

void reverse(string &ans, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    swap(ans[start], ans[end]);
    start++;
    end--;

    reverse(ans, start, end);
}
int main()
{
    string str = "abcddedd";
    int ans = -1;
    // solve(0, str,ans, 'd');
    reverse(str, 0, str.length() - 1);
    cout << str << " ";
    return 0;
}