
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
        t = new TNODE();
        t->key = x;
        t->pLeft = t->pRight = nullptr;
    }
    else
    {
        if(x < t->key)
            makenode(t->pLeft, x);
        else if( x > t->key)
            makenode(t->pRight, x);
    }
}
void CreateTree(TREE& t)
{
    int x;
    while(cin >> x)
    {
        if( x == -1)
            break;
        makenode(t,x);
    }
}
int CountLeaf(TREE t)
{
    if(t == nullptr)
        return 0;
    if(t->pLeft == nullptr && t->pRight == nullptr)
        return 1;
    else
        return CountLeaf(t->pLeft) + CountLeaf(t->pRight);
}
// insert code here

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	cout << CountLeaf(T);
	return 0;
}

/*
test case
Input	Output
6 5 7 2 8 1 -1
2
5 8 3 1 4 9 7 -1	4
6 -1
1
-1
0
test case
*/
