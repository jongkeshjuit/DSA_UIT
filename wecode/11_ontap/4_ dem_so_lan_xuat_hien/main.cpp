
#include <iostream>
using namespace std;

// insert code here
struct TNODE{
    int key;
    int count;
    TNODE* pLeft;
    TNODE* pRight;
};

typedef struct TNODE* TREE;

void makenode(TREE& t, int x)
{
    if(t == nullptr)
    {
        t = new TNODE;
        t->key = x;
        t->count = 1;
        t->pLeft = t->pRight = nullptr;
    }
    else
    {
        if(x < t->key) makenode(t->pLeft, x);
        else if(x > t->key) makenode(t->pRight, x);
        else t->count++;
    }
}

void CreateTree(TREE& t)
{
    int n;
    cin >> n;
    for(int i = 0; i < n ; ++i)
    {
        int x;
        cin >> x;
        makenode(t, x);
    }
}

void PrintTree(TREE t)
{
    if(t != nullptr)
    {
        PrintTree(t->pLeft);
        cout << t->key << " xuat hien " << t->count << " lan " << endl;
        PrintTree(t->pRight);
    }
}
// insert code here


int main() {
	TNODE* T;
	T = NULL;
	CreateTree(T);
	PrintTree(T);
	return 0;
}
