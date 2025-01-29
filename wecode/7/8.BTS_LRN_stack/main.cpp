
#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;
// insert code here
void CreateEmptyTree(TREE &T) {
	T = NULL;
}
TNODE* CreateTNode(int x) {
	TNODE *p=new TNODE; //cấp phát vùng nhớ động
	p->key = x; //gán trường dữ liệu của node = x
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}
int Insert(TREE &T, TNODE *p) {
	if (T) {
		if (T->key == p->key) return 0;
		if (T->key > p->key)
			return Insert(T->pLeft, p);
		return Insert(T->pRight, p);
	}
	T = p;
	return 1;
}

void CreateTree(TREE &T){
	int x;
	do {
		cin >> x;
		if(x==-1) break;
		Insert(T, CreateTNode(x));
	}while(true);
}
#include <stack>
void PrintTree(TREE t)
{
    if( t == nullptr)
    {
        cout << "Empty Tree." << endl;
        return;
    }
    stack<TNODE*> s, out;
    s.push(t);
    while(!s.empty())
    {
        TREE current = s.top();
        s.pop();
        out.push(current);
        if(current->pLeft != nullptr) s.push(current->pLeft);
        if(current->pRight != nullptr) s.push(current->pRight);
    }
    while(!out.empty())
    {
        cout << out.top()->key << " ";
        out.pop();
    }
}
// insert code here

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);
	PrintTree(T);
	return 0;
}

/*
Input	Output
6 5 7 2 8 1 -1     1 2 5 8 7 6
4 8 1 9 -1          1 9 8 4
-1
Empty Tree.*/
