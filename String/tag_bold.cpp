#include <bits/stdc++.h>
using namespace std;

void makeBold(string &str, vector<string> &tags)
{
    vector<bool> bold(str.length(), false);

    for (auto it : tags)
    {
        int position = str.find(it, 0);

        while (position != string::npos)
        {
            for (int i = position; i < position + it.size(); i++)
            {
                bold[i] = true;
            }

            position = str.find(it, position + 1);
        }
    }

    bool inBold = false;

    for (int i = 0; i < str.length(); i++)
    {
        if (bold[i] == true && !inBold)
        {
            inBold = true;
            cout << "<b>";
        }
        else if (!bold[i] && inBold)
        {
            inBold = false;
            cout << "</b>";
        }

        cout << str[i] << "";
    }

    if (inBold)
    {
        cout << "</b>";
    }
}

int main()
{
    string str = "aaaabcdfg";
    vector<string> tags = { "ab", "cd", "g"};

    makeBold(str, tags);

    return 0;
}
