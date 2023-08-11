class Solution {
public:
    bool isValid(string s)
    {
        if(s[0] != 'a') 
        {
            return false;
        }


        stack<char>st;

        for(int i = 0; i<s.length(); i++)
        {
            if(s[i] == 'a')
            {
                st.push(s[i]);
            }
            else if(s[i] == 'b')
            {
                if(!st.empty() && st.top() == 'a')
                {
                    st.push(s[i]);
                }
                else
                {
                    return false;
                }
            }
            else 
            {
                // s[i] == c

                if(!st.empty() && st.top() == 'b')
                {
                    st.pop();

                    if(!st.empty() && st.top() == 'a')
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }

            }
        }

        return st.empty()==1 ? true : false;
    }


// Approach 2:
    // time complexity : o(N^2)
    bool isValid(string s) {

        if(s.length() == 0)
        {
            return true;
        }

        int pos = s.find("abc");
        // gives position of first charachter..  and if string is not present then it will return string::npos

        if(pos != string::npos)
        {
            string left = s.substr(0,pos);
            string right = s.substr(pos+3, s.length());

            return isValid(left + right);
        }

        return false;
        
    }
};