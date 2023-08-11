class Solution {
public:
   
    void generateString(stack<string>& st, string& ans) {
        if (st.empty()) {
            return; 
        }

        string s = st.top();
        st.pop(); 

        generateString(st, ans); 

        ans += s; 
    }

    string simplifyPath(string path) {
        stack<string> st; 

        int i = 0;

        while (i < path.length()) {
            int start = i;
            int end = i + 1;

            // Find the end of the directory name
            while (end < path.size() && path[end] != '/') {
                end++;
            }

            string p1 = path.substr(start, end - start);

            i = end;

            if (p1 == "/" || p1 == "/.") {
                continue; // Skip unnecessary or current directory references
            }

            if (p1 != "/..") {
                st.push(p1); // Push valid directory names onto the stack
            } else if (!st.empty()) {
                st.pop(); // Handle parent directory references by popping from stack
            }
        }

        string ans = st.empty() ? "/" : ""; 

        generateString(st, ans); 

        return ans; 
    }
};