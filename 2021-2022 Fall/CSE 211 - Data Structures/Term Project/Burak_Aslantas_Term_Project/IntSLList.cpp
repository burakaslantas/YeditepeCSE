/* @Author
 * Student Name: Burak Aslantas
 * Student ID: 20190702029
 * Date: 28.12.2021
 */
#include "IntSLList.h"
#include <string>

IntSLList::~IntSLList()
{
    for( IntSLLNode *p; !isEmpty(); )
    {
        p = head->next;
        delete head;
        head = p; 
    }
}

void IntSLList::addToHead( string el )
{
    head = new IntSLLNode( el,head );
    if( tail == 0 )
    {
        tail = head;
    }
    
	size++;
}

void IntSLList::addToMiddle( int x, string el )
{
    IntSLLNode* newNode = new IntSLLNode( el );
    IntSLLNode *tmp = head;
    
    if( x >= 1 && x <= size )
	{
	    size++;
	    
	    for( int i = 1; i < (x - 1) && tmp != NULL; i++ )
	    {
		    tmp = tmp->next;
	    }
	    
	    newNode->next = tmp->next;
	    tmp->next = newNode;
	}
}

void IntSLList::addToTail( string el )
{
    if( tail != 0 )
    {
        tail->next = new IntSLLNode( el );
        tail = tail->next;
    }
    else
    {
        head = tail = new IntSLLNode( el );
    }
    
	size++;
}

string IntSLList::GetAt( int x )
{
	IntSLLNode *tmp = head;
	
	if( x >= 1 && x <= size )
	{
	    for( int i = 1; i < x && tmp != NULL; i++ )
	    {
		    tmp = tmp->next;
	    }
	    
	    return tmp->info;
	}
	
	return "0cb7c3e488b4184f68801f9898e63b4471dfe1d72487e3046de60c105cc4b043"; // sha-256 hash, for edge cases
}

void IntSLList::ReplaceInfoAtNode( int x, string line )
{
    IntSLLNode *tmp = head;
    
	for( int i = 1; i < x && tmp != NULL; i++ )
	{
		tmp = tmp->next;
	}
	
	tmp->info = line;
}

int IntSLList::GetSize()
{
	return size;
}

string IntSLList::deleteFromHead()
{
    string el = head->info;
    IntSLLNode *tmp = head;
    
    if (head == tail)
    {
        head = tail = 0;
    }
    else
    {
        head = head->next;
    }
    
    delete tmp;
	size--;
	return el;
}

string IntSLList::deleteFromTail()
{
    string el = tail->info;
    
    if (head == tail)
    {
        delete head;
        head = tail = 0;
    }
    else
    {
        IntSLLNode *tmp;
        
        for(tmp = head; tmp->next != tail; tmp = tmp->next);
        
        delete tail;
        tail = tmp;
        tail->next = 0;
    }
    
	size--;
    return el;
}

void IntSLList::deleteNode(string el)
{
    if( head != 0 )
    {
        if ( head == tail && el == head->info )
        {
            delete head;
            head = tail = 0;
        }
        else if( el == head->info )
        {
           IntSLLNode *tmp = head;
           head = head->next;
           delete tmp;
        }
        else
        {
            IntSLLNode *pred, *tmp;
            
            for( pred = head, tmp = head->next;
                tmp != 0 && !(tmp->info == el);
                pred = pred->next, tmp = tmp->next );
                 
            if( tmp != 0 )
            {
                pred->next = tmp->next;
                
                if( tmp == tail )
                {
                   tail = pred;
                }
                
                delete tmp;
            }
        }
    }
}

bool IntSLList::isInList(string el) const
{
    IntSLLNode *tmp;
    
    for( tmp = head; tmp != 0 && !(tmp->info == el); tmp = tmp->next );
    
    return tmp != 0;
}

void IntSLList::printAll() const
{
    for( IntSLLNode *tmp = head; tmp != 0; tmp = tmp->next )
    {
        cout << tmp->info << " ";
    }
    
	cout << endl;
}



