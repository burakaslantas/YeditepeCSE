//************************  intSLList.cpp  **************************

#include <iostream>
#include "intSLList.h"

using namespace std;

IntSLList::~IntSLList() {
    for (IntSLLNode *p; !isEmpty(); ) {
        p = head->next;
        delete head;
        head = p;
    }
}

void IntSLList::addToHead(int el) {
    head = new IntSLLNode(el,head);
    if (tail == 0)
       tail = head;
}

void IntSLList::addToTail(int el) {
    if (tail != 0) {      // if list not empty;
         tail->next = new IntSLLNode(el);
         tail = tail->next;
    }
    else head = tail = new IntSLLNode(el);
}

int IntSLList::deleteFromHead() {
    int el = head->info;
    IntSLLNode *tmp = head;
    if (head == tail)     // if only one node on the list;
         head = tail = 0;
    else head = head->next;
    delete tmp;
    return el;
}

int IntSLList::deleteFromTail() {
    int el = tail->info;
    if (head == tail) {   // if only one node on the list;
         delete head;
         head = tail = 0;
    }
    else {                // if more than one node in the list,
         IntSLLNode *tmp; // find the predecessor of tail;
         for (tmp = head; tmp->next != tail; tmp = tmp->next);
         delete tail;
         tail = tmp;      // the predecessor of tail becomes tail;
         tail->next = 0;
    }
    return el;
}

void IntSLList::deleteNode(int el) {
    if (head != 0)                     // if non-empty list;
         if (head == tail && el == head->info) { // if only one
              delete head;                       // node on the list;
              head = tail = 0;
         }
         else if (el == head->info) {  // if more than one node on the list
              IntSLLNode *tmp = head;
              head = head->next;
              delete tmp;              // and old head is deleted;
         }
         else {                        // if more than one node in the list
              IntSLLNode *pred, *tmp;
              for (pred = head, tmp = head->next; // and a non-head node
                   tmp != 0 && !(tmp->info == el);// is deleted;
                   pred = pred->next, tmp = tmp->next);
              if (tmp != 0) {
                   pred->next = tmp->next;
                   if (tmp == tail)
                      tail = pred;
                   delete tmp;
              }
         }
}

bool IntSLList::isInList(int el) const {
    IntSLLNode *tmp;
    for (tmp = head; tmp != 0 && !(tmp->info == el); tmp = tmp->next);
    return tmp != 0;
}

void IntSLList::printAll() const {
    for (IntSLLNode *tmp = head; tmp != 0; tmp = tmp->next)
        cout << tmp->info << " ";
	cout << endl;
}

int IntSLList::find_min() {
    IntSLLNode *cur = head;
    int minimumValue = cur->info;
    if (cur->next != NULL)
    {
        cur = cur->next;
        for( ; cur != NULL; cur = cur->next)
        {
            if (cur->info < minimumValue)
            {
                minimumValue = cur->info;
            }
        }
    }
    
	return minimumValue;
}

IntSLList IntSLList::sort_list(){
    IntSLList list;
    IntSLList list2;
    IntSLLNode *cur = head;
    
    for( ; cur != NULL; cur = cur->next )
    {
        list.addToTail(cur->info);
    }
    
    while(list.head != NULL)
    {
        int min = list.find_min();
        list.swap_nodes(min);
        list2.addToTail(list.deleteFromHead());
    }
    
    /*
    //Solution 2
    
    IntSLLNode *temp = list.head;
 
    while (temp) {
        IntSLLNode *min = temp;
        IntSLLNode *remaining = temp->next;
 
        while (remaining) {
            if (min->info > remaining->info)
                min = remaining;
 
            remaining = remaining->next;
        }
 
        int i = temp->info;
        temp->info = min->info;
        min->info = i;
        temp = temp->next;
    }
    
    return list;
    */
    
    cout << "intsllist.cpp içinde list: ";
    list2.printAll();
    
	return list2;
}

void IntSLList::swap_nodes(int val) {
    IntSLLNode *cur = head;
    int originalHeadValue = cur->info;
    cur->info = val;
    cur = cur->next;
    for ( ; cur != NULL; cur = cur->next)
    {
        if(val == cur->info)
        {
            cur->info = originalHeadValue;
        }
    }
}


