
#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

//insert code here
// Tạo node mới
TNODE* CreateTNode(int x) {
    TNODE *p = new TNODE;
    p->key = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

// Thêm node vào cây
int Insert(TREE &T, TNODE *p) {
    if (T == NULL) {
        T = p;
        return 1;
    }
    if (T->key == p->key) return 0;
    if (T->key > p->key)
        return Insert(T->pLeft, p);
    return Insert(T->pRight, p);
}

// Tạo cây từ input
void CreateTree(TREE &T) {
    int x;
    do {
        cin >> x;
        if (x == -1) break;
        Insert(T, CreateTNode(x));
    } while (true);
}
// Đếm số node có đúng 1 con
int CountNode_Have1Child(TREE T) {
    // Nếu cây rỗng hoặc là node lá
    if (T == NULL || (T->pLeft == NULL && T->pRight == NULL))
        return 0;

    // Đếm số node có 1 con ở cây con trái và phải
    int count = CountNode_Have1Child(T->pLeft) + CountNode_Have1Child(T->pRight);

    // Kiểm tra node hiện tại có đúng 1 con không
    if ((T->pLeft == NULL && T->pRight != NULL) ||
        (T->pLeft != NULL && T->pRight == NULL))
        count++;

    return count;
}
//insert code here

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);
	cout << CountNode_Have1Child(T);
	return 0;
}
