
#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

//insert code here
void makenode(TREE& t, int x)
{
    if(t == nullptr)
    {
        t = new TNODE;
        t->key = x;
        t->pLeft = t->pRight = nullptr;
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
   while( cin >> x)
   {
       if(x == -1)
            break;
       makenode(t ,x );
   }
}
int SumInternalNode(TREE t)
{
    if(t == nullptr)
        return 0;
    if(t->pLeft == nullptr && t->pRight == nullptr)
        return 0;
    return t->key + SumInternalNode(t->pLeft) + SumInternalNode(t->pRight);

}
//insert code here


int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	cout << SumInternalNode(T);
	return 0;
}
/*
Input	Output
9 16 6 7 2 12 4 11 25 -1	45
5 -1	0
6 7 -1	6
-1	0
*/
