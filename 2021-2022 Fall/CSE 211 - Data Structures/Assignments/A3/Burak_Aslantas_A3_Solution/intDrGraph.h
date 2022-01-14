/* @Author
 * Student Name: Burak Aslantas
 * Student ID: 20190702029
 * Date: 05.12.2021 */

#ifndef INTDRGRAPH_H
#define INTDRGRAPH_H
#include <iostream>
#include "IntSLList.h"
#include <fstream>
#include <string>
#include <vector> // used only for the BONUS part
#include "queue.h"
using namespace std;

class intDrGraph{
private:
    bool error;
	IntSLList **listoflist;
	int arraysize;
	IntSLList *CheckList;
	
public:
	intDrGraph(string filename){
		ifstream file;
		file.open(filename.c_str());
		file >> arraysize;
		int from,to;
		int i = 0;
		
		if(file.is_open() == false){
            cout << "Couldn't open the file" << endl;
            error = true;
            return;
		}
		
		error = false;
        listoflist = new IntSLList *[arraysize];
        
        for( int i = 0; i < arraysize; i++ ) // Iterate "arraysize" times
        {
            listoflist[i] = new IntSLList(); // Create an adjacency list
            listoflist[i]->addToTail(i + 1);
        }

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
		delete CheckList;
	}
	
	void print(void){
	    CheckList->printAll(); // Print CheckList which is created by BFS function
	    cout << "***printAdjList***" << endl;
	    
	    for( int i = 0; i < arraysize; i++ ) // Iterate through adjacency lists
	    {
	        int size = listoflist[i]->GetSize(); // Get current adjacency list's size
	        
	        for( int j = 1; j < size; j++) // Iterate through the nodes in the current adjacency list
	        {
	            cout << listoflist[i]->GetAt(j) << " -> ";
	        }
	        
	        cout << listoflist[i]->GetAt(size);
	        
	        if( size == 1 )
	        {
	            cout << " -> ";
	        }
	        
	        cout << endl;
	    }
	}
	
	void BFS(int starting_index){
	    /*
	        To perform BFS;
	        #1 Take a starting_index
	        #2 Look childs' of parent using adjacency list
	        #3 Enqueue 
	    */
	    if( starting_index < 1 || starting_index > 11 ) // If starting_index is not in our graph, return.
	    {
	        cout << "This is not a valid element. Breadth search couldn't be executed!" << endl;
	        return;
	    }
	    
	    CheckList = new IntSLList;
	    queue<int> myqueue; // To apply BFS Algorithm, we need a First In, First Out (FIFO) approach, that's why we chose to use queue
	    CheckList->addToTail( starting_index ); // Let's call starting_index as "Parent node". Add "Parent node" to CheckList
	    int AdjacentNodeNumber = listoflist[starting_index - 1]->GetSize(); // Find the number of adjacent nodes to "Parent node"
	    
	    for( int i = 2; i < AdjacentNodeNumber + 1; i++ ) // Iterate over the current Parent node's adjacency list, start from first adjacent node in the list
	    {
	        myqueue.enqueue( listoflist[starting_index - 1]->GetAt(i) ); // Enqueue current adjacent node into "myqueue"
	    }
	    // At the end of the for loop, all the adjacent nodes to Parent node", added into "myqueue"
	    while( !myqueue.isEmpty() ) // While "myqueue" is not empty, do the following things
	    {
	        int currentNodeIndex = myqueue.dequeue() - 1; // Take a node from front of queue, let's call this node as "Parent node"
	        int AdjacentNodeNumber = listoflist[currentNodeIndex]->GetSize(); // Find the number of adjacent nodes to "Parent node" 
	        
	        for( int i = 2; i < AdjacentNodeNumber + 1; i++ ) // Iterate over the current Parent node's adjacency list, start from first adjacent node in the list
	        {
	            myqueue.enqueue( listoflist[currentNodeIndex]->GetAt(i) ); // Enqueue current adjacent node into "myqueue"
	        }
            if( !CheckList->isInList( listoflist[currentNodeIndex]->GetAt(1) ) )
            {
                CheckList->addToTail( listoflist[currentNodeIndex]->GetAt(1) );
            }
	    }
	    // At the end of the while loop, BFS Algorithm completed, we traversed through all nodes starting from "starting_index"
	}

	bool isConnected(int src, int dest){
	    BFS(src); // Traverse through all nodes starting from "starting_index", if we can traverse through these nodes this means they are connected
	    if( !CheckList->isInList( dest ) ) // Check our destination node whether connected to starting_index or not
	    {
	        return false;
	    }
	    return true;
	}
	//BONUS Part
	void DFS(int src, int dest, vector<int> path, vector< vector<int> >& allPaths){
	    path.push_back(src); // Add source node to the path
	    if( src == dest ) // If this condition satisfied, this means we find a route from "src_city" to "dest_city"
	    {
	        allPaths.push_back(path); // Add current path to the allPaths
	    }
	    else // If current route hasn't been completed (if we haven't reached the dest_city yet), do the following things
	    {
	        int size = listoflist[src - 1]->GetSize() + 1; // Find number of adjacent nodes of src
	        for( int i = 2; i < size; i++ ) // Iterate through adjacent nodes of src
	        {
	            DFS(listoflist[src - 1]->GetAt(i), dest, path, allPaths); // Call "DFS" for every adjacent nodes of src, 
	            // so here we are doing Depth first search by using recursion
	            // To apply DFS Algorithm, we need a Last In, First Out (LIFO) approach, that's why we need to use stack
	            // Recursion operation creates a "call stack", this is what we need. We don't need to create a stack, recursion operation already created the "call stack" for us.
	        }
	    }
	    path.pop_back();
	}
	
	void findRoutes( int src_city, int dest_city ){
	    vector< vector<int> > allPaths;
	    vector<int> path;
	    DFS( src_city , dest_city, path, allPaths );
	    cout << "..:: BONUS - Find Routes ::.." << endl;
	    cout << "Calculated all possible paths from \"" << src_city << "\" to \"" << dest_city << "\"." << endl;
	    if(!allPaths.size())
	    {
	        cout << "There is no any path." << endl;
	    }
	    for(auto path: allPaths)
	    {
	        for(auto j: path)
	        {
	            cout << j << " ";
	        }
	        cout << endl;
	    }
	}
};

#endif
