#ifndef QUEUE_H
#define QUEUE_H
#include "dll.h"
#include <iostream>
using namespace std;
template <class T>
class queue{
private:
	DoublyLinkedList<T> *Q;
	float sum; 
	int count;
public:
	queue(){
		Q = new DoublyLinkedList<T> ;
		sum = 0;
		count = 0;
	}
	~queue(){
		delete Q;
	}
	void enqueue(T data){
		count++;
		sum+=data;
		Q->addToDLLTail(data);
	}
	T dequeue(void){
		count--;
		T tmp = Q->deleteFromDLLHead();
		sum-= tmp;
		return tmp;
	}
	T firstElement(void){
		return Q->firstEl();
	}
	bool isEmpty(void){
		return Q->isEmpty();
	}
	void Average1(void){
		cout << "Average = " << sum/count << endl << endl;
	}
	

};

#endif 
