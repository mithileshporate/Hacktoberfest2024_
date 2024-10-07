// Linked List node
struct Node {
    int data;
    struct Node* next;
};
 
// Utility function to create new node
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
 
    return temp;
}
 
// Print singly linked list before conversion
void print(Node* head)
{
    while (head) {
 
        // print current node
        cout << head->data << " ";
        head = head->next;
    }
 
    cout << endl;
}
 
// Function to find XORed value of
// the node addresses
Node* XOR(Node* a, Node* b)
{
    return (Node*)((uintptr_t)(a) ^ (uintptr_t)(b));
}
 
// Function to convert singly linked
// list to XOR linked list
void convert(Node* head)
{
    Node* curr = head;
    Node* prev = NULL;
    Node* next = curr->next;
 
    while (curr) {
 
        // store curr->next in next
        next = curr->next;
 
        // change curr->next to XOR of prev and next
        curr->next = XOR(prev, next);
 
        // prev will change to curr for next iteration
        prev = curr;
 
        // curr is now pointing to next for next iteration
        curr = next;
    }
}
 
// Function to print XORed linked list
void printXOR(Node* head)
{
    Node* curr = head;
    Node* prev = NULL;
 
    while (curr) {
 
        // print current node
        cout << curr->data << " ";
 
        Node* temp = curr;
 
        /* compute curr as prev^curr->next as
           it is previously set as prev^curr->next so
           this time curr would be prev^prev^curr->next 
           which is curr->next */
        curr = XOR(prev, curr->next);
 
        prev = temp;
    }
 
    cout << endl;
}
