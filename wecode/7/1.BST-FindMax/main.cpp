
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
    if(t == nullptr)
    {
        t = new TNODE;
        t->key = x;
        t->pLeft = t->pRight = nullptr;
    }
    else
    {
        if( x < t->key ) makenode(t->pLeft, x);
        if( x > t->key ) makenode(t->pRight, x);
    }
}
void CreateTree(TREE& t)
{
    int x;
    while( cin >> x)
    {
        if( x == -1)
            break;
        makenode(t, x);
    }
}
TNODE* FindMax(TREE t)
{
    if(t == nullptr) return nullptr;
    while(t->pRight != nullptr)
        t = t->pRight;
    return t;
}
// insert code here

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	if(T==NULL) cout << "Empty Tree.";
	else cout << FindMax(T)->key;
	return 0;
}

/*Input	Output	Note
6 5 7 2 8 1 3 -1
8
          6
        /   \
       5     7
     /        \
    2          8
   / \
  1   3
4 8 1 9 0 3 -1	9
      4
    /   \
   1     8
 /  \     \
0     3    9
-1
Empty Tree.	Cây rỗng.*/
