#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

};

Node* head = NULL;
Node* tail = NULL;

void push(int data)
{
    if(head == NULL)
    {
        head = new Node(data);
        tail = head;
    }
    else
    {
        Node* newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }
}

void pop()
{
    if(head == NULL)
    {
        return ;
    }

    else 
    {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
}

int top()
{
    if(head == NULL)
    {
        return 0;
    }

    cout<<head->data<<" ";
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    top();

    pop();

    top();
}