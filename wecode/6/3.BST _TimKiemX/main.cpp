
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
void CreateTree(TREE& t)
{
    int x;
    while( cin >> x)
    {
        if(x == -1)
            break;
        else
            makenode(t,x);
    }
}
bool searchNode(TREE t, int x)
{
    if(t == NULL)
        return false;
    if(t->key == x)
        return true;
    if(x < t->key)
        return searchNode(t->pLeft, x);
    else
        return searchNode(t->pRight, x);
}
//insert code here

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	int x;
	cin >> x;
	if(searchNode(T, x)) cout << "true";
	else cout << "false";
	return 0;
}

/*
test case
Input	Output
6 5 7 2 8 1 -1
6
true

4 8 1 9 -1
2
false

-1
7
false
test case
*/
