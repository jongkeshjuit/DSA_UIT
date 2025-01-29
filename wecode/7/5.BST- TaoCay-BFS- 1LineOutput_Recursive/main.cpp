
#include <iostream>
#include <queue>
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
int Height(TREE t)
{
    if(t == nullptr) return 0;
    int leftheight = Height(t->pLeft);
    int rightheight = Height(t->pRight);
    if(leftheight > rightheight) return leftheight + 1;
    else return rightheight + 1;
}
void PrintLevel(TREE t, int level)
{
    if(t == nullptr) return;
    if(level == 1) cout << t->key << " ";
    if(level > 1)
    {
        PrintLevel(t->pLeft, level - 1);
        PrintLevel(t->pRight, level - 1);
    }
}
void PrintTreeBFS(TREE t)
{
    if( t == nullptr)
    {
        cout << "Empty Tree.";
        return;
    }
    int h = Height(t);
    for(int i = 1 ; i <= h; i++)
        PrintLevel(t, i);
}
// insert code here


int main() {
	TNODE* T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);
	PrintTreeBFS(T);
	return 0;
}

/*Input	Output
9 16 6 7 2 12 4 11 25 1 20 -1	9 6 16 2 7 12 25 1 4 11 20
-1	Empty Tree.*/

