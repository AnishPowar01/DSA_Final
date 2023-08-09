#include <bits/stdc++.h>
using namespace std;
void print(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

void insertSorted(stack<int> &st, int num)
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

    int elem = st.top();
    st.pop();

    insertSorted(st, num);

    st.push(elem);
}

void sortIt(stack<int> &st)
{
    if (st.size() == 0)
    {
        return;
    }

    int num = st.top();
    st.pop();

    sortIt(st);

    insertSorted(st, num);
}
int main()
{

    stack<int> st;

    st.push(100);
    st.push(200);
    st.push(900);
    st.push(10);
    st.push(700);
    st.push(600);

    sortIt(st);

    print(st);
    return 0;
}