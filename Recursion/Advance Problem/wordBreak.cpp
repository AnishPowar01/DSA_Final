class Solution {
public:
    int dp[302];
    bool solve(int index, string s,unordered_set<string>&st)
    {
        if(index == s.length())
        {
            return true;
        }

        if(dp[index]!=-1)
        {
            return dp[index];
        }


        if(st.find(s)!=st.end())
        {
            return dp[index] = true;
        }



        for(int l = 1; l<=s.length(); l++)
        {
            string temp = s.substr(index, l);

            if(st.find(temp)!=st.end() && solve(index+l, s, st))
            {
                return dp[index] = true;
            }
        }

        return dp[index] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string>st;

        memset(dp, -1, sizeof(dp));

        for(auto it : wordDict)
        {
            st.insert(it);
        }


        return solve(0, s, st);
    }
};