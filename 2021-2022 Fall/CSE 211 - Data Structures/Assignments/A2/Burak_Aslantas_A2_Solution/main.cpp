/* @Author
 * Student Name: Burak Aslantas
 * Student ID: 20190702029
 * Date: 17.11.2021 */

#include <iostream>
#include <string>
#include "codeStack.h"

using namespace std;

int main() {

    codeStack stk, undoStk;
    char chr = 'a';
    string input;
    
    // For debugging purposes you may uncomment the lines below:
    /*stk.pushToStack("chr");
    stk.pushToStack("a");
    stk.pushToStack("b");
    
    stk.printStack();
    stk.popFromStack();
    stk.printStack();*/
    // Debug END
    
    // User input interface. You may want to check what "c_str()" does to solve the problem.
    cout << "Please enter text below.\n------------\nTooltip:\n\nUse 'Enter' to commit,\nUse the command '/delete' to delete,\nUse the command '/undo' to undo the deletion,\nUse the command '/print' to view the document,\nUse the command 'reversePrint' to view the document in-order,\nUse the command '/exit' to exit.\n------------";
    while (true) {
        // Get the user input into a buffer.
        cout << "\nInput: ";
        getline (cin, input);
        
        // Main interface.
        // Exit function
        if (!input.compare("/exit")) {
            cout << endl << "The last state of the document is:" << endl << "----------------" << endl;
            stk.printReverseStack();
            break;
        }
        // Handle the deletion for this assignment. There is a reason we declared two stacks.
        // This should do some transition between stk and undoStk, right? We need to store what we delete.
        if (!input.compare("/delete")) {
            undoStk.pushToStack( stk.popFromStack().c_str() ); // Pop from the stack called "stk" and push node to undoStk.
        }
        // Handle the undo for this assignment. There is a reason we declared two stacks.
        // This should do some transition between stk and undoStk, right? We need to restore what we deleted.
        else if (!input.compare("/undo")) {
            stk.pushToStack( undoStk.popFromStack().c_str() ); // Pop from the stack called "undoStk" and push node to stk.
        }
        // Print functions
        else if (!input.compare("/reversePrint"))
            stk.printReverseStack();
        else if (!input.compare("/print"))
            stk.printStack();
        // Input function
        else {
            // We use "string" function type but cannot input strings to functions.
            // You may try to do it at home and see how mad your compiler gets at you when you try so.
            // e.g. void testFunction(string s)
            // I wonder what magic allows us to pass strings to functions...
            stk.pushToStack(input.c_str());
            // Hint: It's in the line of code above.
            
            // We shouldn't be able to undo things to irrelevant places, right?
            undoStk.~codeStack();
            // Yes, a destructor is a usable thing.
        }
    }
    
    return 0;
}
