#include <bits/stdc++.h>
using namespace std;
void solve(int index, string &s, vector<string> &ans, unordered_set<string> &st, string temp)
{
    if (index >= s.length())
    {
        temp.pop_back();
        ans.push_back(temp);
        return;
    }

    string word = "";

    for (int i = index; i < s.length(); i++)
    {
        word += s[i];

        if (st.find(word) != st.end())
        {
            solve(i + 1, s, ans, st, temp + word + ' ');
        }
    }
}
int main()
{

    // Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
    // Output: ["cats and dog","cat sand dog"]

    string s = "catsanddog";

    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};

    vector<string> ans;

    unordered_set<string> st(wordDict.begin(), wordDict.end());

    solve(0, s, ans, st, "");

    for (auto it : ans)
    {
        cout << it << ""<<endl;
    }

    return 0;
}