#include <bits/stdc++.h>
using namespace std;
string solve(string&input, unordered_map<char, int>&mapping)
{

    if(input.size() == 0)
    {
        return ""; 
    }


    string ans = "";

    for(auto it : input)
    {
        if(mapping.find(tolower(it)) != mapping.end())
        {
            ans += to_string(mapping[tolower(it)]);
        }
        else
        {
            ans += it;
        }
    }

    return ans;

}
int main()
{
    unordered_map<char, int> mapping = {

        {'a', 2}, {'b', 2}, {'c', 2}, {'d', 3}, {'e', 3}, {'f', 3}, {'g', 4}, {'h', 4}, {'i', 4}, {'j', 5}, {'k', 5}, {'l', 5}, {'m', 6}, {'n', 6}, {'o', 6}, {'p', 7}, {'q', 7}, {'r', 7}, {'s', 7}, {'t', 8}, {'u', 8}, {'v', 8}, {'w', 9}, {'x', 9}, {'y', 9}, {'z', 9}
    };

    

    string input = "Aniish";

    string ans = solve(input, mapping);

    cout<<ans<<" ";
    return 0;
}