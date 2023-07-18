// see explanation here
// https://leetcode.com/problems/find-all-anagrams-in-a-string/solutions/3781526/simple-c-sliding-window-approach/
class Solution {
private:
    bool CheckAllZero(const vector<int>& counter) {
        // Function to check if all counts in the counter are zero
        for (auto it : counter) {
            if (it != 0) {
                return false;
            }
        }
        return true;
    }

public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();

        vector<int> ans;  // Vector to store indices of anagrams found

        vector<int> counter(26, 0);  // Counter to store counts of characters

        // Count occurrences of characters in string p
        for (auto it : p) {
            counter[it - 'a']++;
        }

        int i = 0;
        int j = 0;

        // Sliding window approach to find anagrams
        while (j < n) {
            counter[s[j] - 'a']--;  // Decrease count of character at j

            if (j - i + 1 == m) {  // If window size equals length of p
                if (CheckAllZero(counter)) {
                    ans.push_back(i);  // All counts are zero, found anagram
                }

                counter[s[i] - 'a']++;  // Increase count of character at i
                i++;  // Move window start to the right
            }

            j++;  // Move window end to the right
        }

        return ans; 
    }
};
