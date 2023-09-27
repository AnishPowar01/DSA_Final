class Solution {
private:
    bool isPalindrom(string & str)
    {
        int s = 0;
        int e = str.length() -1;

        while(s<e)
        {
            if(str[s] != str[e])
            {
                return false;
            }

            s++;
            e--;
        }

        return true;
    }
    void solve(int index, string&s, vector<vector<string>>&ans, vector<string>op)
    {
        if(index >= s.length())
        {
            ans.push_back(op);
            return;
        }


        for(int i = index; i<s.length(); i++)
        {
            string palin = s.substr(index, i-index+1);

            if(isPalindrom(palin))
            {
                op.push_back(palin);
                solve(i+1, s, ans, op);
                op.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {

        vector<vector<string>>ans;
        vector<string>temp;

        solve(0, s, ans, temp);
        return ans;
    }
};