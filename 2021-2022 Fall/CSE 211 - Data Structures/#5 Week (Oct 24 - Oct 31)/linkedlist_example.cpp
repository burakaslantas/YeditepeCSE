#include <iostream>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;

        SinglyLinkedList() {
            this->head = nullptr;
        }

};

void print_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        cout << node->data << "-->";

        node = node->next;

    }
    if(node== NULL)
        cout<<"null"; 
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* head, int data) {

    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    
    //SinglyLinkedListNode* newNode =(SinglyLinkedListNode*)(malloc(sizeof(SinglyLinkedListNode)));
    //newNode -> next = NULL;
    //newNode -> data = data;
    
        if (head == NULL)
            head = newNode;
        else {
           newNode->next = head;
           head = newNode;
        }
        
    return newNode;
    
}

int main()
{

    SinglyLinkedList* llist = new SinglyLinkedList();

    int llist_count;
    cin >> llist_count;
    cin.ignore();

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore();
    
      	SinglyLinkedListNode* llist_head = insertNodeAtHead(llist->head, llist_item);
        llist->head = llist_head;
    }

    print_singly_linked_list(llist->head);
    cout << "\n";

    free_singly_linked_list(llist->head);


    return 0;
}

