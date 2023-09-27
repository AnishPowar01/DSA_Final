class Solution {
public:
    void solve(int index, string& digits, string temp, string mapping[], vector<string>&ans)
    {
        if(index >= digits.size())
        {
            ans.push_back(temp);
            return;
        }


        int val = digits[index] - '0';

        string word = mapping[val];

        for(int i = 0; i<word.size(); i++)
        {
            temp.push_back(word[i]);
            solve(index+1, digits, temp, mapping, ans);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {

        if(digits.size() == 0)
        {
            return {};
        }


        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        string temp = "";

        vector<string>ans;


        solve(0, digits, temp, mapping, ans);


        return ans;
        
    }
};