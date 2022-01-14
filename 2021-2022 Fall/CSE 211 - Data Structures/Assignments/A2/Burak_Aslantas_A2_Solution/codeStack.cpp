/* @Author
 * Student Name: Burak Aslantas
 * Student ID: 20190702029
 * Date: 17.11.2021 */

#include <iostream>
#include <string>
#include "codeStack.h"

using namespace std;

// Destructor, no need to meddle with.
codeStack::~codeStack() {
    for (stackNode *p; !isEmpty(); ) {
        p = top->next;
        delete top;
        top = p;
    }
}

// Fill in for this assignment.
// So we need to create some new node and attach it, right?
// But the added node should be our top while being connected to its behind.
void codeStack::pushToStack(const char* s) {
    stackNode *newTop = new stackNode(s, top); // Create new node with the info is s and it's points to top of the stack.
    top = newTop; // Update top, now it points to newTop.
    return;
}

// Fill in for this assignment
string codeStack::popFromStack() {
    // Main case: Stack is not empty while we are popping something.
    // This if statement is where you should work, then.
    // We are deleting some node, reassigning our top node to the
    // second topmost element and return the deleted node's info.
    string s = "\0"; // Default string value.
    
    if (top != 0) { // If stack is non empty.
        s = top->info; // Take top info into string called "s".
        stackNode *newTop = top->next; // Create next pointer, it points to top node's next node.
        delete top; // Delete top
        top = newTop; // Update top, now it points to newTop.
        return s;
    }
    
    // What would you RETURN when there is nothing to delete. No need to meddle with the code below, I'd advise you to check what it does though.
    cout << "Error: Nothing to delete." << endl;
    //throw "Nothing to delete!";
    
    return s;
}

// Fill in for this assignment.
// Keep in your mind that we cannot access elements that aren't on top.
// So we should probably pop to read elements below the top, right?
// popFromStack function deletes from the stack for good,
// so you would want to reconstruct the stack within this, probably.
void codeStack::printStack() {
    codeStack temp; // Create a stack called "temp".
    
    while( !isEmpty() ) // While given stack is non empty.
    {
        const char *currentChar = popFromStack().c_str(); // Pop given stack's top and assign it to the currentChar.
        cout << currentChar; // Print currentChar.
        temp.pushToStack(currentChar); // Push currentChar to the temp stack.
    }
    
    cout << endl;
    
    while( !temp.isEmpty() ) // While temp stack is non empty.
    {
        pushToStack( temp.popFromStack().c_str() ); // Pop temp stack's top and push it back to given stack.
    }
    
    return;
}

// Fill in for this assignment. Why is this necessary?
// If there would be no reverse print, words you wrote would be shown in reverse order.
// Maybe a queue here would be better? Most likely.
// But I think you would prefer to implement only stack and a reverse print instead of both stack and queue.
// So let's just implement a quite similar one to the above with reverse print order.
void codeStack::printReverseStack() {
    codeStack temp; // Create a stack called "temp".
    
    while( !isEmpty() ) // While given stack is non empty.
    {
        temp.pushToStack( popFromStack().c_str() ); // Pop given stack's top and push it to temp stack.
    }
    
    while( !temp.isEmpty() ) // While temp stack is non empty.
    {
        const char *currentChar = temp.popFromStack().c_str(); // Pop temp stack's top and assign it to the currentChar.
        cout << currentChar; // Print currentChar.
        pushToStack( currentChar ); // Push currentChar back to the given stack.
    }
    
    cout << endl;
    
    return;
}

