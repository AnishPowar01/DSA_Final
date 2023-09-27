#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void sortInsertIt(stack<int> &st, int num)
    {
        if (st.size() == 0)
        {
            st.push(num);
            return;
        }

        if (st.top() >= num)
        {
            st.push(num);
            return;
        }

        int number = st.top();
        st.pop();

        sortInsertIt(st, num);

        st.push(number);
    }

public:
    void print(stack<int> &st)
    {
        while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
    }
    void sortStack(stack<int> &st)
    {
        if (st.size() == 0)
        {
            return;
        }

        int num = st.top();
        st.pop();

        sortStack(st);

        sortInsertIt(st, num);
    }
};

int main()
{
    Solution obj;

    stack<int> st;

    st.push(10);
    st.push(9);
    st.push(12);
    st.push(11);
    st.push(30);
    st.push(22);
    st.push(20);
    st.push(89);
    st.push(47);
    st.push(25);

    obj.sortStack(st);

    obj.print(st);

    return 0;
}