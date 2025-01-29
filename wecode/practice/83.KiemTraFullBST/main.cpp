
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

bool IsFullBinaryTree(TREE Root) {
// insert code here
    if(Root == nullptr) return true;
    if((Root->pLeft == nullptr && Root->pRight != nullptr) || (Root->pLeft != nullptr && Root->pRight == nullptr)) return false;
    return IsFullBinaryTree(Root->pLeft) && IsFullBinaryTree(Root->pRight);
// insert code here

}
int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	if(T==NULL) cout << "Empty Tree.";
	else cout << boolalpha << IsFullBinaryTree(T);
	return 0;
}
/*
Input	Output
30 15 50 40 60 55 70 65 80 -1
// Minh họa:
     30
  /     \
15       50
       /    \
     40      60
           /   \
         55     70
               / \
            65     80
True
30 15 5 20 50 40 60 55 70 -1
// Minh họa:
       30
    /     \
   15      50
 /   \    /  \
5     20 40   60
             /  \
           55     70
True
30 50 40 60 80 55 -1
// Minh họa:
       30
         \
          50
         /  \
       40   60
           /  \
         55    80
False
-1	Empty Tree.*/
