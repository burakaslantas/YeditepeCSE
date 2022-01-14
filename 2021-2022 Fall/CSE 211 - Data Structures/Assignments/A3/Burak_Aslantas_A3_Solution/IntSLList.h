/* @Author
 * Student Name: Burak Aslantas
 * Student ID: 20190702029
 * Date: 05.12.2021 */

//************************  intSLList.h  **************************
//           singly-linked list class to store integers

#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST
#include <iostream>
using namespace std; 
class IntSLLNode {
public:
    IntSLLNode() {
        next = 0;
    }
    IntSLLNode(int el, IntSLLNode *ptr = 0) {
        info = el; next = ptr;
    }
    int info;
    IntSLLNode *next;
};

class IntSLList {
public:
	
    IntSLList() {
        head = tail = 0;
		size = 0;
    }
    ~IntSLList();
    int isEmpty() {
        return head == 0;
    }
	int GetSize(void);
	int GetAt(int);
    void addToHead(int);
    void addToTail(int);
    int  deleteFromHead(); // delete the head and return its info;
    int  deleteFromTail(); // delete the tail and return its info;
    void deleteNode(int);
    bool isInList(int) const;
    void printAll() const;
private:
    IntSLLNode *head, *tail;
	int size;
};

#endif
