
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
    if( t == NULL)
    {
        t = new TNODE();
        t->key = x;
        t->pLeft = t->pRight = NULL;
    }
    else
    {
        if(x < t->key)
            makenode(t->pLeft, x);
        else if( x > t->key)
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
TNODE* FindMin(TREE t)
{
    if(t == NULL)
        return NULL;
    while(t->pLeft != NULL)
        t = t->pLeft;
    return t;
}
//insert code here

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	if(T==NULL) cout << "Empty Tree.";
	else cout << FindMin(T)->key;
	return 0;
}

/*
test case
Input	Output	Note
6 5 7 2 8 1 3 -1
1
          6
        /   \
       5     7
     /        \
    2          8
   / \
  1   3
4 8 1 9 0 3 -1	0
      4
    /   \
   1     8
 /  \     \
0     3    9
-1
Empty Tree.	Cây rỗng.
test case
*/
