class Solution {
private:
    vector<int> nextSm(vector<int>&nums)
    {
        int n = nums.size();
        stack<int>st;
        
        st.push(-1);

        vector<int>ans(n);

        for(int i = n-1; i>=0; i--)
        {
            while(st.top()!=-1 && nums[st.top()] >= nums[i])
            {
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }
    vector<int> prevSm(vector<int>&nums)
    {
        int n = nums.size();
        stack<int>st;
        
        st.push(-1);

        vector<int>ans(n);

        for(int i = 0; i<n; i++)
        {
            while(st.top()!=-1 && nums[st.top()] >= nums[i])
            {
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }
public:
    int largetAreaInHistogram(vector<int>&nums)
    {
        vector<int>nextSmaller = nextSm(nums);
        vector<int>prevSmaller = prevSm(nums);

        int n = nums.size();
        int maxi = 0;

        for(int i = 0; i<n;i++)
        {
            int height = nums[i];

            if(nextSmaller[i] == -1)
            {
                nextSmaller[i] = n;
            }

            int width = nextSmaller[i] - prevSmaller[i] -1;

            int area = height * width;

            maxi = max(area, maxi);
        }

        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {

        // apply the logic of larget area in histogram;

        int n= matrix.size();
        int m = matrix[0].size();

        vector<vector<int>>helperMatrix;

        // convert the char matrix to integer;

        for(int i =0; i<n; i++)
        {
            vector<int>oneDmatrix;
            for(int j = 0; j<m; j++)
            {
                oneDmatrix.push_back(matrix[i][j] - '0');
            }
            helperMatrix.push_back(oneDmatrix);
        }

        int maxi = largetAreaInHistogram(helperMatrix[0]);


        for(int  i  = 1; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(helperMatrix[i][j] == 1)
                {
                    // add previous row.  each cell wll act as height of histogram.
                    helperMatrix[i][j] += helperMatrix[i-1][j];
                }
                else
                {
                    helperMatrix[i][j] = 0;
                }
            }

            // apply largest histogram vala logic:

            maxi = max(maxi, largetAreaInHistogram(helperMatrix[i]));
        }

        return maxi;
        
    }
};