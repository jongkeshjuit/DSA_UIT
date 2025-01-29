

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
bool isEqual(TREE t1, TREE t2)
{
    if(t1 == nullptr && t2 == nullptr) return true;
    if(t1 != nullptr && t2 != nullptr)
        return t1->key == t2->key && isEqual(t1->pLeft, t2->pLeft) && isEqual(t1->pRight, t2->pRight);
    return false;
}
// insert code here

int main() {
	TNODE* T1, *T2;
	T1=NULL; T2=NULL;

	CreateTree(T1);
	CreateTree(T2);

	cout << boolalpha << isEqual(T1, T2);

	return 0;
}


/*
Input	Output	Note
30 20 60 10 -1
30 20 60 10 -1	true
      30           30
     /  \         /  \
    20  60      20   60
   /           /
  10          10
30 20 60 10 15 -1
30 20 60 10 -1	false
    30           30
   /  \         /  \
  20  60      20   60
 /  \        /
10   15     10
-1
-1	true
*/
