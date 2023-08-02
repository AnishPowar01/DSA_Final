class Solution {
public:
    int dp[20] = {0}; // Array to store previously computed results to avoid redundant calculations

    int numTrees(int n) {
        if (n <= 1) {
            return 1; // Base case: If n is 0 or 1, there is only one possible BST, return 1.
        }

        if (dp[n] != 0) {
            return dp[n]; // If the result for 'n' is already computed, return it directly.
        }

        int ans = 0;

        // Calculate the number of unique BSTs for 'n' nodes by considering each node as the root once at a time.
        for (int i = 1; i <= n; i++) {
            ans += numTrees(i - 1) * numTrees(n - i); // Recursively calculate left subtree * right subtree.
        }

        return dp[n] = ans; // Store the result for 'n' in dp array and return the result.
    }
};
