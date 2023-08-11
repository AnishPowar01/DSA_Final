class Solution {
public:
    vector<int> findNS(vector<int>&heights)
    {
        stack<int>st;
        st.push(-1);

        vector<int>ans(heights.size());

        for(int i = heights.size()-1; i>=0; i--)
        {
            while(st.top()!= -1 && heights[st.top()] >= heights[i])
            {
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }
    vector<int> findPS(vector<int>&heights)
    {
        stack<int>st;
        st.push(-1);

        vector<int>ans(heights.size());

        for(int i = 0; i<heights.size(); i++)
        {
            while(st.top()!= -1 && heights[st.top()] >= heights[i])
            {
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {

        vector<int>nextSmaller = findNS(heights);
        vector<int>prevSmaller = findPS(heights);

        // for(auto it : nextSmaller)
        // {
        //     cout<<it<<" ";
        // }

        int maxi = INT_MIN;
        int size = heights.size();

        for(int i =0; i<heights.size(); i++)
        {
            int height = heights[i];

            if(nextSmaller[i] == -1)
            {
                nextSmaller[i] = size;
            }

            int width = nextSmaller[i] - prevSmaller[i] - 1;

            int area = height * width;
            maxi = max(maxi, area);
        }

        return maxi;

        
    }
};