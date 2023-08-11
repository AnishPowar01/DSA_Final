class Solution {
public:
    string decodeString(string s) {
        stack<char> st; 

        for (int i = 0; i < s.length(); i++) {

            if (s[i] != ']') {

                st.push(s[i]); 
                // Push characters other than ']'
            } else {
                string word = ""; // Initialize a string to store the enclosed word

                // Construct the enclosed word by popping characters until '[' is encountered
                while (st.top() != '[') {

                    word = st.top() + word; 

                    st.pop();
                }

                st.pop(); // Pop '[' as it has been processed

                string number = ""; 

                // Construct the number by popping digits
                while (!st.empty() && isdigit(st.top())) {

                    number = st.top() + number; 

                    st.pop();
                }

                int k = stoi(number); 

                // add the word k times 
                while (k--) {

                    for (int i = 0; i < word.length(); i++) {

                        st.push(word[i]);
                    }
                }
            }
        }

        string ans = "";

     
        while (!st.empty() && !isdigit(st.top())) {

            ans = st.top() + ans;

            st.pop();
        }

        return ans; 
    }
};
