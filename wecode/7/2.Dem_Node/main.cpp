
#include <iostream>

using namespace std;
struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

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
// insert code here
int CountNode(TREE T)
{
    if( T == nullptr) return 0;
    return CountNode(T->pLeft) + CountNode(T->pRight) + 1;
}
// insert code here

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);
	cout << CountNode(T);
	return 0;
}

/*
Input	Output
6 5 7 2 8 1 -1
6
5 8 3 1 4 9 7 -1	7
6 -1
1
-1
0*/
