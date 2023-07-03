#include<bits/stdc++.h>
using namespace std;

class StackNode{

    public :
    int data;
    StackNode* next;

    StackNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }

};

StackNode * head = NULL;

void push(int data)
{
    if(head == NULL)
    {
        StackNode* node = new StackNode(data);
        head = node;
    }

    else
    {
         StackNode* node = new StackNode(data);
         node ->next = head;
         head = node;

    }

    cout<<"data is pushed"<<endl;
}

bool  isempty()
{

    if(head == NULL)
    {
        cout<<"Empty";
        return 1;
    }
    cout<<"Not Empty";
    return 0;
}

int top()
{
    if(head == NULL)
    {
        return 0;
    }

    cout<<head->data<<" ";
}

void pop()
{
    if(head == NULL)
    {
        return ;
    }

    StackNode* temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
}

int size()
{
    StackNode * temp = head;
    int counter = 0;
    while(temp!=NULL)
    {
        temp = temp->next;
        counter++;
    }

    cout<<"Size is "<<counter<<" "<<endl;

    return 0;
}

int main()
{

    push(10);
    push(50);
    push(40);
    push(30);
    size();

    // top();
    pop();

    top();

    isempty();

    size();
   

}
