class Solution {
public:
    void solve(int opening_count, int closing_count, vector<string>&ans, string temp)
    {

        if(opening_count == 0 && closing_count == 0)
        {
            ans.push_back(temp);
            return;
        }

        if(opening_count > 0)
        {
            string temp1 = temp;
            temp1.push_back('(');
             solve(opening_count-1, closing_count, ans, temp1);
        }

        if(closing_count > opening_count)
        {
            string temp1 = temp;
            temp1.push_back(')');
             solve(opening_count, closing_count-1, ans, temp1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
         solve(n,n,ans, "");

         return ans;
        
    }
};