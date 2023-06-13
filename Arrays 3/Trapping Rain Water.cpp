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