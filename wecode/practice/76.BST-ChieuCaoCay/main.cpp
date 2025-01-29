
#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

//insert code here
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
int Height(TREE t)
{
    if( t == nullptr)
        return -1;
    int leftheight = Height(t->pLeft);
    int righttheight = Height(t->pRight);
    return max(leftheight, righttheight) + 1;
}
//insert code here

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);
	if(T==NULL) cout << "Empty Tree.";
	else cout << Height(T);
	return 0;
}
