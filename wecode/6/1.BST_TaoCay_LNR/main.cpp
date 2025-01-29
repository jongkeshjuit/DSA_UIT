
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
    if(t == NULL)
    {
        t = new TNODE;
        t->key = x;
        t->pLeft = t->pRight = NULL;
    }
    else
    {
        if(x < t->key)
            makenode(t->pLeft, x);
        else if (x > t->key)
            makenode(t->pRight, x);
    }
}
void LNR(TREE root)
{
    if(root != NULL)
    {
        LNR(root->pLeft);
        cout << root->key << " ";
        LNR(root->pRight);
    }
}
void CreateTree(TREE& t)
{
    int x;
    while(cin >> x)
    {
        if(x == -1)
            break;
        makenode(t,x);
    }
}
void PrintTree(TREE t)
{
    if( t == NULL)
        cout << "Empty Tree.";
    else
        LNR(t);
}
//insert code here

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);
	PrintTree(T);
	return 0;
}

/* test case
6 5 7 2 8 1 -1
1 2 5 6 7 8

4 8 1 9 -1
1 4 8 9

-1	Empty Tree.
 test case
*/
