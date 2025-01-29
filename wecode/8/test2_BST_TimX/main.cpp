
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
        if(x < t->key) makenode(t->pLeft, x);
        if(x > t->key) makenode(t->pRight, x);
    }
}
void CreateTree(TREE& t)
{
    int x;
    while(cin >> x && x!= -1)
        makenode(t, x);
}
bool searchNode(TREE t, int x)
{
    if(t == nullptr) return false;
    if(x == t->key) return true;
    if(x < t->key) return searchNode(t->pLeft, x);
    if(x > t->key) return searchNode(t->pRight, x);
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
/*Input	Output
6 5 7 2 8 1 -1
6	true
4 8 1 9 -1
2	false
-1
7	false*/
