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

void insertAtHead(Node* &head, int data)
{
    Node* temp = new Node(data);

    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &head, int data)
{
   Node* temp = new Node(data);

   if(head == NULL)
   {
    head = temp;
   }

   if(head->next == NULL)
   {
    head->next = temp;
   }

   Node* itera = head;

   while(itera->next!=NULL)
   {
    itera = itera->next;
   }

   itera->next = temp;

}

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

void insertAtPosition(Node* &head, int data, int pos)
{
    Node* newNode = new Node(data);

    if(pos == 1)
    {
        insertAtHead(head, data);
    }

    Node* temp = head;

    int counter = 1;


    while(counter < pos - 1)
    {
        temp = temp->next;
        counter++;
    }

    if(temp->next == NULL)
    {
        insertAtTail(head,data);
    }

   
    Node* helper = NULL;

    newNode->next = temp->next;

    temp->next = newNode;
}

void deleteNode(Node* &head, int pos)
{
    if(pos == 1)
    {
        Node* temp = head;

        head = head->next;

        temp->next = NULL;

        delete temp;
    }
    else
    {
        Node* prev = NULL;
        Node* temp = head;
     

        int counter = 1;

        while(counter < pos)
        {
            prev = temp;
            temp = temp->next;
            counter++;
        }

        prev->next = temp->next;

        temp->next = NULL;

        delete temp;

        

  

    }
}

int main()
{
    Node* head = new Node(10);
    insertAtHead(head,20);
    insertAtHead(head,30);
    insertAtHead(head,40);
    insertAtHead(head,10);

    printNode(head);

    insertAtTail(head, 100);

    printNode(head);

    insertAtPosition(head, 50, 4);

    printNode(head);

    deleteNode(head, 4);

    printNode(head);


    



    // cout<<head->data<<" ";


    return 0;
}