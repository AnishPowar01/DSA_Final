class Solution
{
private:
    void solve(int index, string temp, vector<string> &ans, int n)
    {
        if (index == n)
        {
            ans.push_back(temp);
            return;
        }

        temp.push_back('0');
        solve(index + 1, temp, ans, n);
        temp.pop_back();

        if (temp.back() == '0' || temp.size() == 0)
        {
            temp.push_back('1');
            solve(index + 1, temp, ans, n);
        }
    }

public:
    vector<string> generateString(int N)
    {
        // Write your code here.
        string temp = "";
        vector<string> ans;

        solve(0, temp, ans, N);

        return ans;
    }
};
