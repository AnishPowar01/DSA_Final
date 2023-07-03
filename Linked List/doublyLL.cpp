#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void printNode(Node* head)
{
    Node* temp = head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" "<<"-> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
    cout<<endl<<endl;
}

void insertAtHead(Node* & head, Node* & tail, int data)
{
    if(head == NULL)
    {
        Node* temp = new Node(data);

        head = temp;
        tail = temp;

    }
    else
    {

        Node* temp = new Node(data);

        temp->next = head;
        head->prev = temp;
        head = temp;

    }
}

void insertAtTail(Node* head, Node* tail, int data)
{
    Node* temp = new Node(data);

    if(tail == NULL)
    {
        tail = temp;
        head = temp;
    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}


void insertAtPosition(Node* head, Node* tail, int pos, int data)
{
    if(pos == 1)
    {
        insertAtHead(head, tail, data);
    }

    int counter  = 1;

    Node* temp = head;

    while(counter < pos - 1)
    {
        temp = temp->next;
        counter++;
    }

    if(temp->next == NULL)
    {
        insertAtTail(head, tail, data);
    }

    Node* newNode = new Node(data);
    
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteNode(Node* &head, int pos)
{
    if(pos == 1)
    {
        Node* temp = head;
        temp->next->prev = NULL;
        head= head->next;
        temp->next = NULL;

        delete temp;
    }

    else
    {
        Node* prevNode = NULL;
        Node* curr = head;

        int cnt = 1;
        while(cnt < pos) {
            prevNode = curr;
            curr = curr -> next;
            cnt++;
        }

        prevNode->next = curr->next;
        curr->prev = NULL;
        curr->next->prev = prevNode;
        curr->next = NULL;

        delete curr;


    }
}



int main()
{

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head,tail,10);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,30);

    printNode(head);
   

   insertAtTail(head, tail, 40);

   printNode(head);

   insertAtPosition(head, tail , 4, 80);

   printNode(head);

   deleteNode(head, 4);

   printNode(head);
}