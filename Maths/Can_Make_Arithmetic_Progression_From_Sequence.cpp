// Approach 1 : O(n)

class Solution {

    public:
    bool canMakeArithmeticProgression(vector<int>& arr) {

        // Arithmetic Progression

        // a+0d, a+d, a+2d, a+3d, .........., a+(n-1)d;

        unordered_set<int>mp(arr.begin(), arr.end());

        int n = arr.size();

        int mini = *min_element(arr.begin(), arr.end());  // a+0d

        int maxi = *max_element(arr.begin(), arr.end()); // a + (n-1) d

        // substract mini and maxi to get d

        //  a - (a + (n-1)d) = constant

        //  d = constant / n-1

        if((maxi - mini)%(n-1) != 0)
        {
            return 0;    // fraction is not present in array
        }


        int d = (maxi - mini) / (n-1);


        int i = 0; 


        while(i<n)
        {
            int number = mini + (i * d);

            if(mp.find(number) == mp.end())
            {
                return 0;   // not in ap.. as element is not present in set
            }
            
            i++;
        }

        return 1;

    }

};


// Aprroach 2 : O(nlogn)
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {

        sort(arr.begin(), arr.end());

        int diff = arr[1] - arr[0];

        for(int i = 2; i<arr.size(); i++)
        {
            if(arr[i] - arr[i-1] != diff)
            {
                return 0;
            }
        } 

        return 1;
        
    }
};



