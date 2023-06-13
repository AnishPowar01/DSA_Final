// Approach 1 : 
// Time Complexity : O(N) + O(N) + O(N); => O(N);
// Space Complexity : O(N) + O(N) + O(N); => O(N);

class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        vector<int>maxl(n);
        vector<int>maxR(n);

        maxl[0] = height[0];

        // calculate the left maximum

        for(int i = 1; i<n; i++)
        {
            maxl[i] = max(maxl[i-1], height[i]);
        }

        // calculate the right maximum

        maxR[n-1] = height[n-1];

        for(int i = n-2; i>=0; i--)
        {
            maxR[i] = max(maxR[i+1],height[i]);
        }


        int sum = 0; 

        vector<int>water(n);

        for(int i = 0; i<n; i++)
        {
            water[i] = min(maxl[i],maxR[i]) - height[i];
            sum += water[i]; 
        }

        return sum;
    }
};



// Approach 2 : 

// Time Complexity :  O(N);
// Space Complexity : O(1);


class Solution{
    public:
    int trap(vector<int>& height)
    {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int ans = 0;
        int leftMax = 0;
        int rightMax = 0;


        while(left<=right)
        {
            if(height[left] <= height[right]) 
            {
                // consider left side.. 

                if(height[left] >= leftMax)
                {
                    leftMax = height[left];
                }
                else
                {
                    ans += leftMax - height[left];
                }

                left++;
            }

            else
            {

                 if(height[right] >= rightMax)
                {
                    rightMax = height[right];
                }
                else
                {
                    ans += rightMax - height[right];
                }

                right--;

            }


        }

        return ans;
    }
};

