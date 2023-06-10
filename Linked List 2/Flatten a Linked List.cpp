
/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node* merge(Node* l1 ,Node* l2)
{
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    
    if(l1->data < l2->data)
    {
        l1->bottom = merge(l1->bottom, l2);
        return l1;
    }
    else
    {
        l2->bottom = merge(l1, l2->bottom);
        return l2;
    }
}
Node *flatten(Node *root)
{
   // Your code here
   
   if(root == NULL || root->next == NULL)
   {
       return root;
   }
   
   Node* rightNode = root->next;
   
   root->next = NULL;
   
   rightNode = flatten(rightNode);
   
   
   Node* ans = merge(root, rightNode);
   
   
   return ans;
}

