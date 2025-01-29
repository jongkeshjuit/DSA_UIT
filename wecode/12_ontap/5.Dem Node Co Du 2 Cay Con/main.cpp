
#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

//insert code here
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
    while( cin >> x && x != -1)
        makenode(t, x);
}
void CountNode_Have2Child(TREE t, int &count)
{
    if(t)
    {
        if(t->pLeft != nullptr && t->pRight != nullptr)
                count++;
        CountNode_Have2Child(t->pLeft, count);
        CountNode_Have2Child(t->pRight, count);
    }
}
//insert code here

int main() {
	int count=0;
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);
	CountNode_Have2Child(T, count);
	cout << count;
	return 0;
}
