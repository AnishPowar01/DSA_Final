#include<bits/stdc++.h>
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
void reverse(stack<int>&st)
{
    if(st.size() == 0)
    {
        return;
    }

    int num = st.top();
    st.pop();

    reverse(st);

    insertAtBottom(st,num);
}
void print(stack<int>st)
{
     while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
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
    cout<<"Before reversal"<<endl;
    print(st);


    reverse(st);

    cout<<"After reversal"<<endl;

    print(st);


    return 0;
}