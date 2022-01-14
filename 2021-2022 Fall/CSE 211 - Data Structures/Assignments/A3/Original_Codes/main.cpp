#include<iostream>
#include "intDrGraph.h"
#include <string>

#include "queue.h"

using namespace std;

int main(void){
    string filename;
    int src=5;
    int dst=11;
    int element;
    cout << "What's the filename?" << endl;
    getline(cin,filename);
	intDrGraph Gr(filename);
	cout << "Which element you'd like to start to breadth search? " << endl;
	cin >> element;
	Gr.BFS(element);
	Gr.print();
	if (Gr.isConnected(src, dst) == 1)
		cout << "there is a way from " << src << " to " << dst << endl;
	else 
		cout << "there isn't any way from " << src << " to " << dst << endl;

}
