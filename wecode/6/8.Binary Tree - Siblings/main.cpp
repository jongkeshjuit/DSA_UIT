
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

TNODE* FindParent(TREE Root, const int &x) {
	if(Root==NULL) return NULL;
	if(Root->key==x) return NULL;

	TNODE *pre=NULL;
	TNODE *p = Root;
	while (p != NULL) {
		if (x == p->key) return pre;
		pre=p;
		if (x < p->key)	p = p->pLeft;
		else	p = p->pRight;
	}
	return NULL;
}

//insert coder here
void FindSiblings(TREE T, int &x) {
    // Case 1: Empty tree
    if (T == NULL)
    {
        cout << "Empty Tree.";
        return;
    }
    // Case 2: X is root
    if (T->key == x)
    {
        cout << x << " is Root.";
        return;
    }
    // Find parent of node X
    TNODE* parent = FindParent(T, x);
    // Case 3: X not found in tree
    if (parent == NULL)
    {
        cout << "Not found " << x << ".";
        return;
    }
    // Case 4: Check for siblings
    if (parent->pLeft && parent->pRight)
    {
        // Both children exist
        if (parent->pLeft->key == x)
        {
            // X is left child, right child is sibling
            cout << x << " and " << parent->pRight->key << " are siblings.";
            return;
        }
        if (parent->pRight->key == x)
        {
            // X is right child, left child is sibling
            cout << parent->pLeft->key << " and " << x << " are siblings.";
            return;
        }
    }
    // Case 5: No siblings
    cout << x << " has no siblings.";
}
//insert coder here


int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	int x;
	cin >> x;

	FindSiblings(T, x);

	return 0;
}




/*
Input	Output
-1
7	Empty Tree.
30 15 50 -1
30
// Minh họa:
    30
 /     \
15      50

30 is Root.
30 15 50 -1
40
// Minh họa:
    30
 /     \
15      50

Not found 40.
30 15 50 60 55 70 65 80 -1
60
 // Hình vẽ minh họa:
    30
 /     \
15      50
          \
          60
          /  \
        55     70
              /  \
            65    80

60 has no siblings.
30 15 50 40 60 55 70 65 80 -1
50
// Minh họa:
    30
 /     \
15      50
       /  \
     40   60
          /  \
        55     70
              /  \
            65    80

15 and 50 are siblings.
// Lưu ý: hiển thị các giá trị theo thứ tự left right.*/
