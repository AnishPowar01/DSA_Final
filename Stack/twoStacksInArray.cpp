#include<bits/stdc++.h>
using namespace std;
class Stack{
    int *arr;
    int size;
    int top1;
    int top2;

    public :
    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        this->top1 = -1;
        this->top2 = size;
    }

    void push(int data)
    {
        if(top2 - top1 == 1)
        {
            cout<<"Stack Overlflow"<<endl;
        }

        top1++;
        arr[top1] = data;

    }
    void push1(int data)
    {
         if(top2 - top1 == 1)
        {
            cout<<"Stack Overlflow"<<endl;
        }

        top2--;
        arr[top2] = data;

    }
    void pop()
    {

        if(top1 == -1)
        {
            cout<<"stack underflow"<<endl;
        }

        top1--;
    }

    void pop2()
    {

         if(top2 == size)
        {
            cout<<"stack underflow"<<endl;
        }

        top2++;

    }

    int peek1()
    {
        return arr[top1];
    }

    int peek2()
    {
        return arr[top2];
    }

    void print()
    {
        for(int i =0; i<size; i++)
        {
            cout<<arr[i]<<" ";
        }
    }
};
int main()
{

    Stack st(10);

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);
    st.push1(100);
    st.push1(200);
    st.push1(300);


    cout<<endl;

    //   st.print();


    cout<<st.peek1()<<endl;
    cout<<st.peek2();

    st.pop();
    st.pop2();

    cout<<st.peek1()<<endl;
    cout<<st.peek2();

    return 0;
}