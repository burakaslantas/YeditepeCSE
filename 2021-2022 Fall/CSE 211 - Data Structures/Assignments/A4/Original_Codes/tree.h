#include <iostream>
#include <vector>
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

	Tree() {
		root = NULL;
	}

	void insertBST(int el) {
	
	}

	void insertWrong(int el){

	}

	bool isThisaBST(TreeNode<T>* treeNode){

	}

	int findHeight(TreeNode<T>* treeNode){

	}

	vector<int> findOnlyChild(TreeNode<T>* treeNode){

	}


	void inOrder(TreeNode<T>* treeNode){
		 
	}

};

