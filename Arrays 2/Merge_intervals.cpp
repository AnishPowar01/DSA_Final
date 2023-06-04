class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // sort the array

        sort(intervals.begin(), intervals.end());

        vector<vector<int>>ans;

        int n = intervals.size();
 

        for(int i = 0; i<n; i++)
        {
            if(ans.size() == 0)
            {
                // if ans size == 0 then push the first interval of intervals
                ans.push_back(intervals[i]);
            }
            else
            {
                // get the previous intervla;

                vector<int>&prev  = ans.back();

                // we have to compare the end of prev inteval with the start of current interval;

                int end = prev[1];     //  [1,3] -> prev[1]= 3

                // compare with current;

                if(intervals[i][0] <= end)    // intervals[i][0] = 2
                {
                    prev[1] = max(end, intervals[i][1]);   // intervals[i][1] = 6
                    // prev[1] = max(3,6)
                }
                else
                {
                    ans.push_back(intervals[i]);
                }

            }
        }
        
        return ans;
        
    }
};