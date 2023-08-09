#include <bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int> &st, int x)
{
    if (st.empty())
    {
        st.push(x);
        return;
    }

    int num = st.top();
    st.pop();

    insertAtBottom(st, x);

    st.push(num);
}

void print(stack<int>st)
{
     while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}
int main()
{
    stack<int> st;

    st.push(100);
    st.push(200);
    st.push(300);
    st.push(800);
    st.push(700);
    st.push(600);

    cout << st.top() << ""<<endl;

    insertAtBottom(st, 69);

    cout << st.top() << ""<<endl;


    print(st);

    return 0;
}