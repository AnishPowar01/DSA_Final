// Time Complexity :
// O(log(max(a, b, c))
class Solution {
public:
    int minFlips(int a, int b, int c) {

        int flip_count = 0;

        while(a > 0 ||  b > 0 ||  c > 0)
        {
            // Get the last bit of each number
            int last_bit_A = a & 1;  // If a = 2 -> 0010 & 1 => 0  
            int last_bit_B = b & 1;  // If b = 6 -> 0110 & 1 => 0 
            int last_bit_C = c & 1;  // If c = 5 -> 0101 & 1 => 1

            // Determine the flip count based on the last bits

            // If the last bit of c is 0, we need to find a number with a last bit of 0
            // because when we perform a bitwise OR operation between the two numbers,
            // only then we get 0 as the output.
            if(last_bit_C == 0)
            {
                // Add the flip count for each number's last bit that needs to be flipped
                flip_count += last_bit_A + last_bit_B;
            }
            else 
            {
                // If the last bit of c is 1, either of the numbers' last bit should have 1
                // in order to get 1 as the last bit after performing the OR operation.
                // If both numbers have 0 as the last bit, we need to flip at least one of them.
                if(last_bit_A == 0 && last_bit_B == 0 )
                {
                    flip_count += 1;
                }
            }

            // Right shift the numbers by 1 to get the next bits for comparison
            a = a >> 1;
            b = b >> 1;
            c = c >> 1;
        }

        return flip_count;  // Return the total flip count
    }
};
