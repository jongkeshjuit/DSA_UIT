
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
    if( t == nullptr)
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
        if( x == -1) break;
        makenode(t, x);
    }
}
void PrintTreeBFS(TREE t)
{
    if(t == nullptr)
    {
        cout << "Empty Tree." << endl;
        return;
    }
    queue<TREE> q;
    q.push(t);
    while(!q.empty())
    {
        int countnode = q.size();
        while(countnode > 0)
        {
            TREE node = q.front();
            cout << node->key << " ";
            q.pop();
            if(node->pLeft != nullptr) q.push(node->pLeft);
            if(node->pRight != nullptr) q.push(node->pRight);
            countnode --;
        }
        cout << endl;
    }
}
// insert code here

int main() {
	TNODE* T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);
	PrintTreeBFS(T);
	return 0;
}

/*
Input	Output
9 16 6 7 2 12 4 11 25 1 20 -1
9
6 16
2 7 12 25
1 4 11 20
-1	Empty Tree.*/
