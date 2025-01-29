
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
        if(x > t->key)
            makenode(t->pRight, x);
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
bool FindAncestors(TREE t, int x)
{
    if(t == nullptr)
        return false;
    if(t->key == x ) return true;
    if(FindAncestors(t->pLeft, x) || (FindAncestors(t->pRight, x)))
    {
        cout << t->key << " ";
        return true;
    }
    return false;
}
void PrintAncestors(TREE t, int x)
{
    if( t == nullptr)
    {
        cout << "Empty Tree.";
        return;
    }
    if( t->key == x)
    {
        cout << "Node is root.";
        return;
    }
    if(!FindAncestors(t, x))
    {
        cout << "-1" << endl;
    }
    else
        cout << endl;
}
// insert code here

int main() {
	TNODE* T;
	int x;

	cin >> x;

	T = NULL;
	CreateTree(T);

	PrintAncestors(T, x);

	return 0;
}

/*
Input	Output	Note
9
9 16 6 7 2 12 4 11 25 1 20 -1	Node is root.
              9
            /   \
          6      16
        /  \    /  \
       2    7  12   25
     /   \    /    /
    1     4  11   20
11
9 16 6 7 2 12 4 11 25 1 20 -1	12 16 9
              9
            /   \
          6      16
        /  \    /  \
       2    7  12   25
     /   \    /    /
    1     4  11   20
30
9 16 6 7 2 12 4 11 25 1 20 -1	-1
              9
            /   \
          6      16
        /  \    /  \
       2    7  12   25
     /   \    /    /
    1     4  11   20
7

-1

Empty Tree.*/
