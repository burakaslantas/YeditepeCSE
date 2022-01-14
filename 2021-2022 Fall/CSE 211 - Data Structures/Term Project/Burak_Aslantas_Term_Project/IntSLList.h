/* @Author
 * Student Name: Burak Aslantas
 * Student ID: 20190702029
 * Date: 28.12.2021
 */
#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST
#include <iostream>
#include <string>
using namespace std; 

class IntSLLNode
{
    public:
        IntSLLNode()
        {
            next = 0;
        }
        IntSLLNode( string el, IntSLLNode *ptr = 0 )
        {
            info = el;
            next = ptr;
        }
        
        string info;
        IntSLLNode *next;
};

class IntSLList
{
    public:
        IntSLList()
        {
            head = 0;
            tail = 0;
    		size = 0;
        }
        
        ~IntSLList();
        
        int isEmpty()
        {
            return head == 0;
        }
        
    	int GetSize(void);
    	string GetAt(int);
    	void ReplaceInfoAtNode(int, string);
        void addToHead(string);
        void addToMiddle(int, string);
        void addToTail(string);
        string deleteFromHead();
        string deleteFromTail();
        void deleteNode(string);
        bool isInList(string) const;
        void printAll() const;
        
    private:
        IntSLLNode *head, *tail;
    	int size;
};

#endif
