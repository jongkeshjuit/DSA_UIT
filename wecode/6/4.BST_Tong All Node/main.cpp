
#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

// insert code here
void makenode(TREE& t, int x)
{
    if(t == NULL)
    {
        t = new TNODE();
        t->key = x;
        t->pLeft = t->pRight = NULL;
    }
    else
    {
        if(x < t->key)
            makenode(t->pLeft, x);
        else if(x > t->key)
            makenode(t->pRight, x);
    }
}
void CreateTree(TREE& t)
{
    int x;
    while(cin >> x)
    {
        if(x == -1)
            break;
        makenode(t, x);
    }
}
int SumNode(TREE t)
{
    if(t == NULL)
        return 0;
    else
        return t->key + SumNode(t->pLeft) + SumNode(t->pRight);
}
// insert code here

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);
	cout << SumNode(T);
	return 0;
}

/*
test case
Input	Output
6 5 7 2 8 1 -1	29
4 8 1 9 -1	22
6 -1	6
-1	0
test case
*/
