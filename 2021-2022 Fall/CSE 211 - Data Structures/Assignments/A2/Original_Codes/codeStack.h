#ifndef CHAR_STACK
#define CHAR_STACK
#include <string>
using namespace std;

class stackNode {

public:
	// There are even two constructors for convenience.
	// Use whichever you would need.
	stackNode(const char* s) {
		info = s;
		next = 0;
	}
	// This one is here because we may want to be able to
	// create some nodes with some specific ->next's.
	stackNode(const char* s, stackNode* ptr) {
		info = s;
		next = ptr;
	}

	string info;
	stackNode* next;
};

class codeStack {
public:
    codeStack() {
		top = 0;
	}
	~codeStack();

	bool isEmpty() {
		return top == 0;
	}
    void pushToStack(const char* s);
    string popFromStack();
    void printStack();
    void printReverseStack();

private:
    stackNode *top;
};

#endif