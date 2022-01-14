#ifndef INTDRGRAPH_H
#define INTDRGRAPH_H
#include <iostream>
#include "intSLList.h"
#include <fstream>
#include <string>
#include "queue.h"
using namespace std;
class intDrGraph{
private:
    bool error;
	IntSLList **listoflist;
	. 
	.
	.
		}
public:
	intDrGraph(string filename){

		ifstream file;
		file.open(filename.c_str());
		file >> arraysize;
		if(file.is_open() == false){
            cout << "Couldn't open the file" << endl;
            error = true;
            return;
		}
		error = false;
		.
		.
		.
        listoflist = new IntSLList *[arraysize];
		.
        .
        .
		int from,to;
		int i = 0;
		while(file.eof() == false){
			file>>from;
			file>>to;
			listoflist[from-1]->addToTail(to);
		}
	}
	~intDrGraph(){
        if(error == true) return;
		for(int i=0;i<arraysize;i++){
			delete listoflist[i];

		}
		delete [] listoflist;
		delete [] CheckList;
	}
	void print(void){
		...
	}
	void BFS(int starting_index){
        ...
	}

	bool isConnected (int src, int dest){ ... }
};

#endif
