class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Queue to perform BFS traversal, where each element is a pair of word and its corresponding step.
        queue<pair<string, int>> q;

        // Use an unordered_set to store the words in the wordList for faster lookup.
        unordered_set<string> st(wordList.begin(), wordList.end());

        // Push the beginWord and its initial step (1) into the queue.
        q.push({beginWord, 1});

        // Mark the beginWord as visited by erasing it from the set.
        st.erase(beginWord);

        while (!q.empty()) {
            string word = q.front().first;
            int step = q.front().second;
            q.pop();

            // If the current word matches the endWord, return the step count as the result.
            if (word == endWord) {
                return step;
            }

            // Explore all possible transformations of the current word.
            for (int i = 0; i < word.length(); i++) {
                char originalWord = word[i];

                // Try replacing the current character with all alphabets (a to z).
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;

                    // Check if the new transformed word exists in the wordList (in the set st).
                    if (st.find(word) != st.end()) {
                        // If the word is found, erase it from the set to mark it as visited.
                        st.erase(word);
                        // Push the transformed word and the incremented step into the queue for further BFS traversal.
                        q.push({word, step + 1});
                    }
                }

                // Revert the transformation back to the original character for the next iteration.
                word[i] = originalWord;
            }
        }

        // If no transformation sequence leads to the endWord, return 0.
        return 0;
    }
};
