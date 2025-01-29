
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
int Height(TREE t)
{
    if( t == nullptr) return -1;
    int leftheight = Height(t->pLeft);
    int rightheight = Height(t->pRight);
    return max(leftheight, rightheight) + 1; // + root
}
// insert code here

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);
	if(T==NULL) cout << "Empty Tree.";
	else cout << Height(T);
	return 0;
}

/*Input	Output
6 5 7 2 8 1 -1
3
4 8 1 9 -1	2
6 -1
0
-1
Empty Tree.*/
