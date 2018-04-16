#pragma once
struct NodeBST
{
	int data = NULL;
	NodeBST* parent = NULL;
	NodeBST* leftSon = NULL;
	NodeBST* rightSon = NULL;
};

class BST
{
private:

	NodeBST * root = NULL;


public:
	BST();
	void add(int i);
	int findMax();
	NodeBST* findMin(NodeBST* t);
	NodeBST * findNode(int i);
	void deleteAtIndex(int i);
	NodeBST* findNext(NodeBST* temp);
	void display();
	void pre(NodeBST* t);
	void nett(NodeBST *current, int indent);
	int getRoot();
	void postDel(NodeBST *t);
	void relese(NodeBST* t);
	void findVal(int val);
	
	~BST();
};

