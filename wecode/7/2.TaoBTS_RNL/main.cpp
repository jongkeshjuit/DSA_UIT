
#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;
// insert code here
void makenode(TREE& t , int x)
{
    if(t == nullptr)
    {
        t = new TNODE;
        t->key = x;
        t->pLeft = t->pRight = nullptr;
    }
    else
    {
        if(x < t->key) makenode(t->pLeft, x);
        if(x > t->key) makenode(t->pRight, x);
    }
}
void CreateTree(TREE& t)
{
    int x;
    while( cin >> x)
    {
        if(x == -1) break;
        makenode(t, x);
    }
}
void RNL(TREE& t)
{
    if(t != nullptr)
    {
        RNL(t->pRight);
        cout << t->key << " ";
        RNL(t->pLeft);
    }
}
void PrintTree(TREE t)
{
    if( t == NULL)
        cout << "Empty Tree.";
    else
        RNL(t);
}
// insert code here

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);
	PrintTree(T);
	return 0;
}

/*
Input	Output
6 5 7 2 8 1 -1	8 7 6 5 2 1
4 8 1 9 -1	9 8 4 1
-1	Empty Tree.*/
