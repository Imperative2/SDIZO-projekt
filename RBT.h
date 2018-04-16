#pragma once
struct NodeRBT
{
	int data = NULL;
	NodeRBT * parent = NULL;
	NodeRBT * leftSon = NULL;
	NodeRBT * rightSon = NULL;
	char color = NULL;
};
class RBT
{
private:
	NodeRBT * root = NULL;
	NodeRBT * sentinel = NULL;
public:
	RBT();
	void add(int i);
	int findMax();
	NodeRBT* findMin(NodeRBT * t);
	NodeRBT* findNode(int i);
	NodeRBT* findNext(NodeRBT* temp);
	void rotL(NodeRBT * A);
	void rotR(NodeRBT * A);
	void display();
	void nett(NodeRBT *current, int indent);
	int getRoot();
	void postDel(NodeRBT *t);
	void repair(NodeRBT * t1);
	void repairDell(NodeRBT * X,NodeRBT * Y,NodeRBT *Z);
	void pre(NodeRBT* t);
	void deleteAt(int i);
	void relese(NodeRBT* t);
	void findVal(int val);


	~RBT();

};

