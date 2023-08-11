#include <bits/stdc++.h>
using namespace std;

int longestValidSubsequence(vector<int>& arr, int k) {
    int n = arr.size();
    unordered_map<int, int> lastIdx; // Map to store the latest index for a particular XOR value
    int maxLength = 1;

    for (int i = 0; i < n; i++) {
        if (lastIdx.find(arr[i] ^ k) != lastIdx.end()) {
            int prevIdx = lastIdx[arr[i] ^ k];
            maxLength = max(maxLength, i - prevIdx + 1);
        }

        if (lastIdx.find(arr[i]) == lastIdx.end()) {
            lastIdx[arr[i]] = i;
        }
    }

    return maxLength;
}

int main()
{
    vector<int> arr = {2,1,3,5,2};
    int k = 2;
    int n = arr.size();

    cout << longestValidSubsequence(arr, k)<<" ";
    return 0;
}