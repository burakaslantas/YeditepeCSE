/* @Author
 * Student Name: Burak Aslantas
 * Student ID: 20190702029
 * Date: 16.12.2021
 */
#include <iostream>
#include <vector>
using namespace std;
template <class T>
class Tree;

template <class T>
class TreeNode {
private:
	TreeNode<T> * left;
	TreeNode<T> * right;
	int data;

public:
	TreeNode(const T & el) {
		data = el;
		left = NULL;
		right = NULL;
	}

	friend class Tree<T>;
};


template<class T>
class Tree {

public:
	TreeNode<T> * root;
	TreeNode<T> * treeNodePrev = NULL;
	vector<int> vectorFindOnlyChild;

	Tree() {
		root = NULL;
	}

	void insertBST(int el) {
	    TreeNode<T> * newNode = new TreeNode<T>( el ); // Create a new "TreeNode", newNode is a pointer which is points to the newly created node
	    //          .---.
	    //         | el | <-------------------------|
	    //         '___'        | newNode (Pointer) |
	    //        /    \        |-------------------|
	    //      /       \
	    //    NULL     NULL
	    TreeNode<T> * childPtr = root;
	    TreeNode<T> * parentPtr = NULL;
	    
	    while( childPtr != NULL ) // Iterate on Tree to find the "parent node". The node pointed by "newNode" pointer, will be child of the "parent node"
	    {
	        parentPtr = childPtr;
	        
	        if( el < childPtr->data )
	        {
	            childPtr = childPtr->left;
	        }
	        else
	        {
	            childPtr = childPtr->right;
	        }
	    }
	    
	    if( parentPtr == NULL ) // 1. Case, tree is empty
	    {
	        parentPtr = newNode;
	        root = parentPtr;
	    }
	    else if( el < parentPtr->data ) // 2. Case, value of the node will be added is smaller than the "parent node"
	    {
	        parentPtr->left = newNode;
	    }
	    else // 3. Case, value of the node will be added is bigger than the "parent node"
	    {
	        parentPtr->right = newNode;
	    }
	}
    
	void insertWrong(int el){
        TreeNode<T> * newNode = new TreeNode<T>( el ); // Create a new "TreeNode", newNode is a pointer which is points to the newly created node
	    //          .---.
	    //         | el | <-------------------------|
	    //         '___'        | newNode (Pointer) |
	    //        /    \        |-------------------|
	    //      /       \
	    //    NULL     NULL
	    TreeNode<T> * childPtr = root;
	    TreeNode<T> * parentPtr = NULL;
	    
	    while( childPtr != NULL ) // Iterate on Tree to find the "parent node". The node pointed by "newNode" pointer, will be child of the "parent node"
	    {
	        parentPtr = childPtr;
	        childPtr = childPtr->right;
	    }
	    
	    if( parentPtr == NULL ) // 1. Case, tree is empty
	    {
	        parentPtr = newNode;
	        root = parentPtr;
	    }
	    else // 2. Case, tree is not empty, then add the node pointed by "newNode" into chosen random location (right side of the "parent node")
	    {
	        parentPtr->right = newNode;
	    }
	}
    
	bool isThisaBST(TreeNode<T>* treeNode){
        if( treeNode == NULL ) // Tree is empty
        {
            return true;
        }
        if( !isThisaBST( treeNode->left ) ) // Recursively check left subtree of the treeNode
        {
            return false;
        }
        if( treeNodePrev != NULL && treeNodePrev->data >= treeNode->data ) // treeNodePrev's value is must be smaller than treeNode's value while traversing on the tree using inorder traverse method, if this is not satisfies, return false
        {
            return false;
        }
        treeNodePrev = treeNode; // Update treeNodePrev
        return isThisaBST( treeNode->right ); // Recursively check right subtree of the treeNode
	}

	int findHeight(TreeNode<T>* treeNode){
        if( treeNode == NULL ) // Tree is empty
        {
            return 0;
        }
        return max( 1 + findHeight(treeNode->left), 1 + findHeight(treeNode->right) ); // Return the maximum height between left subtree and right subtree
	}
	
	vector<int> findOnlyChild(TreeNode<T>* treeNode){
        if( treeNode != NULL ) // Tree is not empty
		 {
		     if( treeNode->left != NULL )
		     {
		         findOnlyChild( treeNode->left ); // Recursively check for left subtree of the treeNode
		     }
		     
		     if( treeNode->left != NULL && treeNode->right == NULL || treeNode->left == NULL && treeNode->right != NULL  ) // If treeNode has only one child, either left one or right one
		     {
		         if(treeNode->left != NULL) // If treeNode has a child from left side
		         {
		             vectorFindOnlyChild.push_back( treeNode->left->data ); // Visit that child, add that into vector
		         }
		         else // If treeNode has a child from right side
		         {
		             vectorFindOnlyChild.push_back( treeNode->right->data ); // Visit that child, add that into vector
		         }
		     }
		     
		     if( treeNode->right != NULL )
		     {
		         findOnlyChild( treeNode->right ); // Recursively check for right subtree of the treeNode
		     }
		 }
        return vectorFindOnlyChild;
	}

	void inOrder(TreeNode<T>* treeNode){
		 if( treeNode != NULL ) // Tree is empty
		 {
		     if( treeNode->left != NULL )
		     {
		         inOrder( treeNode->left ); // Recursively check for left subtree of the treeNode
		     }
		     
		     cout << treeNode->data << " "; // Visit treeNode, and print the value of treeNode
		     
		     if( treeNode->right != NULL )
		     {
		         inOrder( treeNode->right ); // Recursively check for right subtree of the treeNode
		     }
		 }
	}
};

