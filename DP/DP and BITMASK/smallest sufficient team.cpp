
// https://leetcode.com/problems/smallest-sufficient-team/solutions/3774672/easy-c-solution-dp-bitmask/

// check the detailed explaination above

class Solution {
public:
    int target;
    int n, m;
    vector<int>result;

    unordered_map<string,int>dp;
    //  string_length

    void solve(int index, vector<int>&people_skill, vector<int>&temp, int mask)
    {
        if(index >= people_skill.size())
        {
            if(mask == target)
            {
                if(result.size() == 0 || result.size() >= temp.size())
                {
                    result = temp;
                }
            }

            return;
        }


        if(result.size()!=0 && result.size() <= temp.size())
        {
            return;
        }

        string key = to_string(index) + "_" + to_string(mask);

        if(dp.find(key)!=dp.end())
        {
            if(dp[key] <= temp.size())
            {
                return;
            }
        }


        // skip

        solve(index+1, people_skill, temp, mask);

        // take
        if(mask | people_skill[index] != mask)
        {
        temp.push_back(index);
        solve(index+1, people_skill, temp, mask | people_skill[index]);
        temp.pop_back();

        dp[key] = (temp.size() != 0) ? temp.size() : -1;

        }

      
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {

         n = req_skills.size();
         m = people.size();

        //req skill mapping

        unordered_map<string,int>skills;

        for(int i = 0; i<n; i++)
        {
            string skill_name = req_skills[i];

            skills[skill_name] = i;
        }


        vector<int>people_skill;

        for(auto &it : people)
        {
            int skill_bit = 0;

            for(auto &skill : it)
            {
                string name = skill;
                int index = skills[skill];

                skill_bit = skill_bit | (1<<index);
            }

            people_skill.push_back(skill_bit);
        }

        // for(auto it : people_skill)
        // {
        //     cout<<it<<" ";
        // }


        target = pow(2,n) - 1;
        vector<int>temp;

        solve(0, people_skill, temp, 0);


        return result;
    }
};