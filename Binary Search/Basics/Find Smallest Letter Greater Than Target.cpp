
// Time Complexity : 
// O(log(n))
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        int start = 0;
        int end = letters.size() -1;
        int index = -1;

        while(start <= end)
        {
            int mid = start + (end - start)/2;

            if(letters[mid] > target)
            {
                index = mid;
                end = mid - 1;

            }
            else
            {
                start = mid +1;
            }
        }

        if(index >= letters.size())
        {
            return letters[0];
        }

        return letters[index];
        
    }
};