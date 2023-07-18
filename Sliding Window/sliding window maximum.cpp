class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        list<int> temp;  // List to store elements in descending order
        vector<int> ans;  // Vector to store maximum elements

        int i = 0;
        int j = 0;

        while (j < nums.size()) {

            while (temp.size() > 0 && temp.back() < nums[j]) {

                temp.pop_back();  // Remove elements smaller than the current element from the back
            }

            temp.push_back(nums[j]);  // Push the current element to the back of the list


            if (j - i + 1 < k) {

                j++;  // Expand the window size

            } else if (j - i + 1 == k) {

                ans.push_back(temp.front());  // Store the maximum element at the front of the list

                if (temp.front() == nums[i]) {

                    temp.pop_front();  
                    // we will  remove it from list if it is maximum.. and if not there are no need to remove it.. beacause we havent's push it into temp;
                }

                i++;  // Move the window start to the right

                j++;  // Move the window end to the right
            }
        }

        return ans; 
    }
};
